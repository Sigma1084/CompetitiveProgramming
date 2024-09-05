#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
class SparseTable {
public:
    using Merger = std::function<T(const T&, const T&)>;

    // A few examples of merge functions can be passed to the constructor
    static T min (const T &a, const T &b) { return std::min(a, b); }
    static T max (const T &a, const T &b) { return std::max(a, b); }
    static T gcd (const T &a, const T &b) { return std::gcd(a, b); }
    static T lcm (const T &a, const T &b) { return std::lcm(a, b); }
    static T bitAnd (const T &a, const T &b) { return a & b; }
    static T bitOr (const T &a, const T &b) { return a | b; }

private:
    int K;
    std::vector<std::vector<T>> st;
    Merger merge;

    T query(int l, int r, int k) {
        return merge(st[k][l], st[k][r - (1 << k) + 1]);
    }

public:
    SparseTable() = default;
    SparseTable(const SparseTable<T> &st) = default;
    template<class V>
    SparseTable(const std::vector<V> &a, Merger merge) { build(a, merge); }

    template<class V>
    void build(const std::vector<V> &a, Merger _merge) {
        merge = _merge;
        K = std::__lg(a.size());

        st.resize(K + 1);
        std::size_t n = a.size();
        st[0].resize(n);
        std::copy(a.begin(), a.end(), st[0].begin());

        for (int i = 1; i <= K; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j < static_cast<int>(n - (1 << i) + 1); j++) {
                st[i][j] = merge(
                    st[i - 1][j],
                    st[i - 1][j + (1 << (i - 1))]
                );
            }
        }
    }

    const std::vector<std::vector<T>>& operator () () const {
        return st;
    }

    T query(int l, int r) {
        if (l > r) {
            throw std::invalid_argument("l must be <= r");
        } else {
            int k = std::log2(r - l + 1);
            return merge(st[k][l], st[k][r - (1 << k) + 1]);
        }
    }
};

class Tree {
protected:
    int n = 0;
    int root = -1;

    // Store the edges
    std::vector<std::vector<int>> edges;

    // DFS
    std::vector<int> parent;
    std::vector<int> depth;
    std::vector<int> subtreeSize;

    // Euler tour
    std::vector<int> _tour;  // tour[i] = i-th node in the euler tour
    std::vector<int> _in;    // in[u] = index of u in the euler tour
    std::vector<int> _out;   // out[u] = last index of the subtree of u
    std::vector<int> _loc;   // loc[i] = location of i-th node in the euler tour

    void dfs(int u) {
        _tour.push_back(u);
        _in[u] = _tour.size() - 1;
        _out[u] = _tour.size() - 1;

        for (auto v: edges[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            dfs(v);
            subtreeSize[u] += subtreeSize[v];
        }

        _out[u] = _tour.size() - 1;
    }

public:
    Tree() = default;

    Tree(const Tree &et) = default;

    Tree(const std::vector<std::vector<int>> &edges, int _root = 0) {
        buildET(edges, _root);
    }

    void buildET(const std::vector<std::vector<int>> &_edges, int _root = 0) {
        edges = _edges;
        n = edges.size();
        root = _root;

        _tour.reserve(n);
        _in.resize(n);
        _out.resize(n);
        parent.resize(n);
        depth.resize(n);
        subtreeSize.resize(n, 1);

        parent[root] = root;
        depth[root] = 0;
        dfs(root);

        _loc.resize(n);
        for (int i = 0; i < n; i++) {
            _loc[_tour[i]] = i;
        }
    }

    constexpr int size () const { return n; }
    const std::vector<std::vector<int>>& e = edges;

    const std::vector<int> &p = parent;
    const std::vector<int> &d = depth;
    const std::vector<int> &sz = subtreeSize;

    const std::vector<int> &tour = _tour;
    const std::vector<int> &in = _in;
    const std::vector<int> &out = _out;
    const std::vector<int> &loc = _loc;
};

class LCATree: public Tree {
    SparseTable<int> rmq;
public:
    using Tree::Tree;

    void buildLCA() {
        if (root == -1) {
            throw std::runtime_error("Tree not built yet");
        } else if (rmq().empty()) {
            rmq.build(_tour, [&](int u, int v) -> int {
                return depth[u] < depth[v] ? u : v;
            });  // Range Min Query on depth
        }
    }

    int lca(int u, int v) {
        if (rmq().empty()) buildLCA();
        return rmq.query(std::min(_in[u], _in[v]),
            std::max(_out[u], _out[v]));
    }
};

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
        return _query(1, l, r);
    }

    void update(int l, int r, U update) {
        _update(1, update, l, r);
    }
};

using T = long long;
using U = long long;
struct SegTree: LazySegTreeBase<T, U> {
    constexpr static T idElement = 0;
    constexpr static U idUpdate = 0;

    SegTree(int n): LazySegTreeBase<T, U>(n, idElement, idUpdate) {}

private:
    T merge(T t1, T t2) override {
        // This is the querying operation
        return t1 + t2;
    }

    U& mergeUpdate(U& update, U newUpdate) override {
        // This is the updating operation
        return update += newUpdate;
    }

    void consume(int node) override {
        tree[node] += sizeOf(node) * lazy[node];
    }
};


void solve() {
    int n, nQ;
    cin >> n >> nQ;

    vector<int> c(n);
    for (auto &x: c) {
        cin >> x;
    }

    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    LCATree tree(g);
    tree.buildLCA();

    SegTree st(n);
    set<array<int, 2>> s;
    for (int u = 0; u < n; ++u) {
        if (c[u] == 1) {
            s.insert({-tree.d[u], u});
            st.update(tree.in[u], tree.out[u], c[u]);
        }
    }

    // tree.in[u], tree.out[u] gives the range of the subtree of u
    // tree.loc[u] gives the location of the node u in the euler tour
    // st.query(loc[u], loc[u]) gives the sum from root to u

    // f[u] := sum from root to u
    auto f = [&](int u) {
        return st.query(tree.loc[u], tree.loc[u]);
    };

    auto info = [&]() {
        cerr << "p: ";
        for (auto x: tree.p) {
            cerr << x + 1 << ' ';
        }
        cerr << '\n';

        cerr << "d: ";
        for (auto x: tree.d) {
            cerr << x << ' ';
        }
        cerr << '\n';

        cerr << "tour: ";
        for (auto x: tree.tour) {
            cerr << x + 1 << ' ';
        }
        cerr << '\n';

        cerr << "in: ";
        for (auto x: tree.in) {
            cerr << x << ' ';
        }
        cerr << '\n';

        cerr << "out: ";
        for (auto x: tree.out) {
            cerr << x << ' ';
        }
        cerr << '\n';

        cerr << "loc: ";
        for (auto x: tree.loc) {
            cerr << x << ' ';
        }
        cerr << '\n';

        cerr << "f: ";
        for (int u = 0; u < n; ++u) {
            cerr << f(u) << ' ';
        }
        cerr << '\n';

        cerr << '\n';
    };

    auto debug = [&]() {
        cerr << "f: ";
        for (int u = 0; u < n; ++u) {
            cerr << f(u) << ' ';
        }
        cerr << '\n';

        cerr << "s: ";
        for (auto [d, u]: s) {
            cerr << "(" << d << ", " << u + 1 << ") ";
        }
        cerr << '\n';
    };

    while (nQ--) {
        int x;
        cin >> x;
        --x;

        if (c[x] == 1) {
            s.erase({-tree.d[x], x});
            st.update(tree.in[x], tree.out[x], -1);
        } else {
            s.insert({-tree.d[x], x});
            st.update(tree.in[x], tree.out[x], 1);
        }

        debug();

        if (s.size() == 0) {
            cout << "No\n";
            continue;
        } else if (s.size() == 1) {
            cout << "Yes\n";
            continue;
        }

        // Consider 2 nodes with the most depth
        auto [d1, u] = *s.begin();
        auto [d2, v] = *next(s.begin());
        auto l = tree.lca(u, v);

        cerr << "u: " << u + 1 << ", v: " << v + 1 << ", l: " << l + 1 << '\n';

        // If l is one of them, it has to be v
        if (l == v) {
            if (f(u) - f(v) + 1 == tree.d[u] - tree.d[v] + 1
                    and tree.d[u] - tree.d[v] + 1 == s.size()) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
            continue;
        }

        // Now, the path from l to u and l to v should be a chain
        int pres = f(u) + f(v) - 2*f(l) + c[l];
        int req = tree.d[u] + tree.d[v] - 2*tree.d[l] + 1;
        if (pres == req and req == s.size()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
