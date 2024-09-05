#include <bits/stdc++.h>
using namespace std;
using ll = long long;


template <typename T, typename U = T>
class LazySegTreeBase {
protected:
    const int n;  // The size of the array
    std::vector<T> tree;  // The segment tree
    std::vector<U> lazy;  // Stores the updates
    std::vector<int> nL, nR;  // Stores the bounds of each node

    // The below functions to be implemented by the user
    virtual T merge(T t1, T t2) = 0;
    virtual U& mergeUpdate(U& update, U newUpdate) = 0;
    virtual void consume(int node) = 0;

    constexpr bool outOfRange(int node, int l, int r) const {
        return nR[node] < l or r < nL[node];
    }

    constexpr bool completelyInRange(int node, int l, int r) const {
        return l <= nL[node] and nR[node] <= r;
    }

    constexpr bool isLeaf(int node) const {
        return node >= n;
    }

    constexpr int sizeOf(int node) const {
        return nR[node] - nL[node] + 1;
    }

private:
    void push(int node) {
        if (lazy[node] == lazy[0]) return;  // Nothing to push

        // Propagate the update to the children
        if (!isLeaf(node)) {
            mergeUpdate(lazy[node * 2], lazy[node]);
            mergeUpdate(lazy[node * 2 + 1], lazy[node]);
        }

        consume(node);  // Consume the update
        lazy[node] = lazy[0];  // Clear the update
    }

    void pull(int node) {
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    T _query(int node, int l, int r) {
        push(node);  // Updating the current node

        if (outOfRange(node, l, r)) return tree[0];
        if (completelyInRange(node, l, r)) return tree[node];

        return merge(_query(node * 2, l, r),
            _query(node * 2 + 1, l, r));
    }

    void _update(int node, U update, int l, int r) {
        // The fact that update is called means there will be a pull
        push(node);  // Have to push before updating

        if (outOfRange(node, l, r)) return;  // node out of range

        if (completelyInRange(node, l, r)) {
            // Perfect overlap.
            lazy[node] = update;
            push(node);
        } else {
            // Partial overlap.
            _update(node * 2, update, l, r);
            _update(node * 2 + 1, update, l, r);
            pull(node);  // a pull is necessary after updating
        }
    }

public:
    LazySegTreeBase(int _n, T idElement = T(), U idUpdate = U()):
            n(1 << std::__lg(2*_n - 1)) {
        tree.resize(2 * n, idElement);
        lazy.resize(2 * n, idUpdate);
        nL.resize(2 * n);
        nR.resize(2 * n);

        std::iota(nL.begin() + n, nL.end(), 0);
        std::iota(nR.begin() + n, nR.end(), 0);

        for (int i = n - 1; i > 0; i--) {
            nL[i] = nL[2 * i];
            nR[i] = nR[2 * i + 1];
        }
    };

    template<class V>
    void assign(const std::vector<V> &v) {
        std::copy(v.begin(), v.end(), tree.begin() + n);
        for (int node = n - 1; node > 0; node--) {
            tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    T query(int l, int r) {
        assert(0 <= l and l <= r and r < n);
        return _query(1, l, r);
    }

    void update(int l, int r, U update) {
        if (l > r) return;
        _update(1, update, l, r);
    }
};

/**
 * 3 types of updates:
 *   1. Add a value to all elements in a range
 *   2. Multiply all elements in a range by a value
 *   3. Divide all elements in a range by a value
 * 
 * Store an update of the form
 * x -> a * x / d + b
 * 
 * Updating again is of the form
 * ax/d + b -> na * (ax/d + b) / nd + nb
 *  -> (na * a) x / (nd * d) + (na * b / nd + nb)
 */

using T = ll;
using U = array<ll, 3>;  // [a, d, b]
struct SegTree: LazySegTreeBase<T, U> {
    constexpr static T idElement = 0;
    constexpr static U idUpdate = {1, 1, 0};

    SegTree(int n): LazySegTreeBase<T, U>(n, idElement, idUpdate) {}

private:
    T merge(T t1, T t2) override {
        // This is the querying operation
        return t1 + t2;
    }

    U& mergeUpdate(U& update, U newUpdate) override {
        // This is the updating operation
        auto &[a, d, b] = update;
        auto [na, nd, nb] = newUpdate;
        b = na * b / nd + nb;
        a = na * a;
        d = nd * d;
    }

    void consume(int node) override {
        auto [a, d, b] = lazy[node];
        tree[node] = a * tree[node] / d + b * sizeOf(node);
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(m), b(m);
    for (auto &x: a) { cin >> x; --x; }
    for (auto &x: b) cin >> x;

    vector<int> iv(n);
    iota(iv.rbegin(), iv.rend(), 0);
    iv[0] = 0;
    SegTree seg(n);
    seg.assign(iv);

    // auto printSeg = [&]() {
    //     for (int i = 0; i < n; ++i) {
    //         cerr << seg.query(i, i) << ' ';
    //     }
    //     cerr << '\n';
    // };

    set<pair<int, int>> s;
    auto processQ1 = [&](int i, int v) {
        // cerr << "Processing " << i << ' ' << v << '\n';
        // cerr << "Before: "; printSeg();
        auto [l, vl] = *prev(s.lower_bound({i, 0}));
        auto [r, vr] = *s.lower_bound({i, 0});
        // The full range [l, r) will get affected
        // First divide by vl
        seg.update(l+1, r-1, {1, vl, 0});
        // cerr << "After div: "; printSeg();
        // Then subtract the nearest right distances
        seg.update(l+1, i, {1, 1, i - r});
        // cerr << "After sub: "; printSeg();
        // Then multiply by v on the right side
        seg.update(i+1, r-1, {v, 1, 0});
        // Multiply by vl on the left side
        seg.update(l+1, i-1, {vl, 1, 0});
        // cerr << "After mul: "; printSeg();
        s.insert({i, v});
        // cerr << '\n';
    };

    for (int i = 0; i < m; ++i) {
        if (a[i] == 0) {
            // Multiply all elements in [0, n-1] by b[i]
            seg.update(1, n-2, {b[i], 1, 0});
            s.emplace(0, b[i]);
            break;
        }
    }
    s.emplace(n-1, 0);

    for (int i = 0; i < m; ++i) {
        if (a[i] == 0 or a[i] == n-1) continue;
        processQ1(a[i], b[i]);
    }

    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, v;
            cin >> i >> v;
            --i;
            processQ1(i, v);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            cout << seg.query(l, r) << '\n';
        } else {
            assert(false);
        }
    }

    for (auto l = 1; l <= n; ++l) {
        for (auto r = l; r <= n; ++r) {
            seg.query(l-1, r-1);
        }
    }

    return 0;
}
