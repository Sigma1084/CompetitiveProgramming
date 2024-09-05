#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T, typename U = T>
class LazySegTreeBase {
protected:
    const unsigned int n;
    std::vector<T> tree;
    std::vector<U> lazy;
    std::vector<int> nL, nR;

    // The below functions to be implemented by the user
    virtual T merge(T t1, T t2) = 0;
    virtual U& mergeUpdate(U& update, U newUpdate) = 0;
    virtual void consume(int node) = 0;

    [[nodiscard]] inline constexpr bool outside(int node, int l, int r) const {
        return nR[node] < l or r < nL[node];
    }

    [[nodiscard]] inline constexpr bool inside(int node, int l, int r) const {
        return l <= nL[node] and nR[node] <= r;
    }

    [[nodiscard]] inline constexpr bool isLeaf(int node) const {
        return node >= n;
    }

    [[nodiscard]] inline constexpr unsigned int sizeOf(int node) const {
        return nR[node] - nL[node] + 1;
    }

private:
    void push(int node) {
        if (lazy[node] == lazy[0]) return;

        // Propagate the update to the children
        if (!isLeaf(node)) {
            mergeUpdate(lazy[node * 2], lazy[node]);
            mergeUpdate(lazy[node * 2 + 1], lazy[node]);
        }

        consume(node);
        lazy[node] = lazy[0];
    }

    void pull(int node) {
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    T query(int node, int l, int r) {
        push(node);

        if (outside(node, l, r)) return tree[0];
        if (inside(node, l, r)) return tree[node];

        return merge(query(node * 2, l, r), query(node * 2 + 1, l, r));
    }

    void update(int node, int l, int r, U up) {
        // The fact that update is called means there will be a pull
        push(node);  // Have to push before updating

        if (outside(node, l, r)) return;  // node out of range

        if (inside(node, l, r)) {
            // Perfect overlap.
            lazy[node] = up;
            push(node);
        } else {
            // Partial overlap.
            update(node * 2, l, r, up);
            update(node * 2 + 1, l, r, up);
            pull(node);
        }
    }

public:
    explicit LazySegTreeBase(int sz, T idT = T(), U idU = U()):
            n(1 << std::__lg(2 * sz - 1)) {
        tree.resize(2 * n, idT);
        lazy.resize(2 * n, idU);
        nL.resize(2 * n);
        nR.resize(2 * n);

        std::iota(nL.begin() + n, nL.end(), 0);
        std::iota(nR.begin() + n, nR.end(), 0);

        for (int i = n - 1; i > 0; i--) {
            nL[i] = nL[2 * i];
            nR[i] = nR[2 * i + 1];
        }
    };

    template<typename V>
    void assign(const std::vector<V> &v) {
        std::copy(v.begin(), v.end(), tree.begin() + n);
        for (int node = n - 1; node > 0; --node) {
            tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    T query(int l, int r) {
        return query(1, l, r);
    }

    void update(int l, int r, U up) {
        update(1, l, r, up);
    }
};

using T = pair<int, int>;
using U = int;
struct SegTree: LazySegTreeBase<T, U> {
    constexpr static T idElement = make_pair(INT_MAX, 0);
    constexpr static U idUpdate = 0;

    SegTree(int n): LazySegTreeBase<T, U>(n, idElement, idUpdate) {}

private:
    T merge(T t1, T t2) override {
        // This is the querying operation
        if (t1.first < t2.first) {
            return t1;
        } else if (t2.first < t1.first) {
            return t2;
        } else {
            return make_pair(t1.first, t1.second + t2.second);
        }
    }

    U& mergeUpdate(U& update, U newUpdate) override {
        // This is the updating operation
        return update += newUpdate;
    }

    void consume(int node) override {
        tree[node].first += lazy[node];
    }
};


void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> aft(n), bef(n);
    SegTree sg(n);
    sg.assign(vector<pair<int, int>>(n, {0, 1}));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        aft[a].push_back(b);
        bef[b].push_back(a);
        sg.update(a, b - 1, 1);
    }

    auto [mn, f] = sg.query(0, n - 1);
    int ans = n - (mn == 0) * f;

    for (int i = 0; i < n; ++i) {
        // The ones that end at i
        for (int s: bef[i]) {
            sg.update(0, n - 1, -1);
            sg.update(s, i - 1, 2);
        }
        // Add the ones that start at i
        for (int e: aft[i]) {
            sg.update(i, e - 1, -2);
            sg.update(0, n - 1, 1);
        }
        tie(mn, f) = sg.query(0, n - 1);
        ans = min(ans, n - (mn == 0) * f);
    }

    cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
