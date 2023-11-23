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

    constexpr auto &getTree() const {
        return tree;
    }
};

constexpr int P = 1e9 + 7;
using T = array<array<int, 2>, 2>;  // [[max, index], [min, index]]
using U = int;
struct SegTree: LazySegTreeBase<T, U> {
    constexpr static T idElement = {{{0, INT_MAX}, {INT_MAX, INT_MAX}}};
    constexpr static U idUpdate = 0;

    SegTree(int n): LazySegTreeBase<T, U>(n, idElement, idUpdate) {}

private:
    T merge(T t1, T t2) override {
        // This is the querying operation
        T res = {{
            max(t1[0], t2[0]),
            min(t1[1], t2[1])
        }};
        if (t1[0][0] == t2[0][0]) {
            res[0][1] = min(t1[0][1], t2[0][1]);
        }
        return res;
    }

    U& mergeUpdate(U& update, U newUpdate) override {
        // This is the updating operation
        return update ^= newUpdate;
    }

    void consume(int node) override {
        // This is the consuming operation
        swap(tree[node][0], tree[node][1]);
        tree[node][0][0] = P - tree[node][0][0];
        tree[node][1][0] = P - tree[node][1][0];
    }
};


void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<array<array<int, 2>, 2>> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = {{{a[i], i}, {a[i], i}}};
    }

    SegTree segTree(n);
    segTree.assign(v);

    ll ans = 0;

    int nQ; cin >> nQ;
    for (int i = 0, l, r; i < nQ; ++i) {
        cin >> l >> r;
        l--, r--;
        segTree.update(l, r, 1);
        ans += segTree.query(0, n-1)[0][1] + 1;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string file_name = "today_is_gonna_be_a_great_day";

    freopen((file_name + "_input.txt").c_str(), "r", stdin);
    freopen((file_name + "_output.txt").c_str(), "w", stdout);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }

    return 0;
}

