#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <typename T, class Compare = std::less<T>>
using OSet = __gnu_pbds::tree<T,
    __gnu_pbds::null_type,
    Compare,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

using namespace std;


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
            n(1 << static_cast<int>(ceil(log2(_n)))) {
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
        return _query(1, l, r);
    }

    void update(int l, int r, U update) {
        _update(1, update, l, r);
    }
};

using pii = pair<int, int>;

// Max Range Query and Assignment Updates
using T = pii;  // [value, prevUpdateTime]
using U = pii;  // [value, prevUpdateTime]
struct SegTree: LazySegTreeBase<T, U> {
    constexpr static T idElement = {0, 0};
    constexpr static U idUpdate = {-1, -1};

    SegTree(int n): LazySegTreeBase<T, U>(n, idElement, idUpdate) {}

private:
    T merge(T t1, T t2) override {
        // This is the querying operation
        return max(t1, t2);
    }

    U& mergeUpdate(U& update, U newUpdate) override {
        // This is the updating operation
        return update = newUpdate;
    }

    void consume(int node) override {
        tree[node] = lazy[node];
    }
};


vector<pii> condensed(vector<pii> &ints) {
    sort(ints.begin(), ints.end());
    vector<pii> res;
    int pL = -1, pR = -1;
    for (auto [l, r]: ints) {
        if (l <= pR) {
            pR = max(pR, r);
        } else {
            if (pL != -1) {
                res.emplace_back(pL, pR);
            }
            pL = l; pR = r;
        }
    }
    if (pL != -1) {
        res.emplace_back(pL, pR);
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // [(0/1), (l/r)]
    vector<vector<pii>> allInts(n);
    OSet<int> oset;
    for (int j = 0; j < m; ++j) {
        int i, l, r;
        cin >> i >> l >> r;
        --i;
        oset.insert(l);
        oset.insert(r);
        allInts[i].emplace_back(l, r);
    }

    int on = oset.size();
    SegTree segtree(on);

    for (auto &ints: allInts) {
        for (auto &[l, r]: ints) {
            l = oset.order_of_key(l);
            r = oset.order_of_key(r);
        }
    }

    vector<int> ans(n + 1);
    int val;
    for (int i = 0; i < n; ++i) {
        auto ints = condensed(allInts[i]);
        pii mx;
        for (auto [l, r]: ints) {
            mx = max(mx, segtree.query(l, r));
        }
        tie(val, ans[i + 1]) = mx;
        for (auto [l, r]: ints) {
            segtree.update(l, r, {val + 1, i + 1});
        }
    }

    auto [len, i] = segtree.query(0, on - 1);
    vector<bool> keep(n + 1, true);
    while (i != 0) {
        keep[i] = false;
        i = ans[i];
    }

    cout << n - len << '\n';
    for (int i = 1; i <= n; ++i) {
        if (keep[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}
