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
        K = std::log2(a.size());

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
            _tour.push_back(u);
            _out[u] = _tour.size() - 1;
        }
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

        _tour.reserve(2 * n - 1);
        _in.resize(n);
        _out.resize(n);
        parent.resize(n);
        depth.resize(n);
        subtreeSize.resize(n, 1);

        parent[root] = root;
        depth[root] = 0;
        dfs(root);
    }

    constexpr int size () const { return n; }
    const std::vector<std::vector<int>>& e = edges;

    const std::vector<int> &p = parent;
    const std::vector<int> &d = depth;
    const std::vector<int> &sz = subtreeSize;

    const std::vector<int> &tour = _tour;
    const std::vector<int> &in = _in;
    const std::vector<int> &out = _out;
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    LCATree tree(g);
    tree.buildLCA();

    int nQ;
    cin >> nQ;

    while (nQ--) {
        int k;
        cin >> k;

        vector<int> a(k);
        for (auto &x: a) {
            cin >> x;
            --x;
        }

        // Sort based on depth
        sort(a.begin(), a.end(), [&](int u, int v) {
            return tree.d[u] > tree.d[v];
        });
        // Highest depth first

        bool ok = true;
        int l = a[0], r = -1, p = 0;
        for (int i = 1; i < k; ++i) {
            if (r == -1) {
                if (tree.lca(a[i], l) == a[i]) {
                    l = a[i];
                } else {
                    r = a[i];
                    p = tree.lca(l, r);
                    if (tree.d[p] > tree.d[a.back()]) {
                        ok = false;
                        break;
                    }
                }
            } else {
                if (tree.lca(a[i], l) == a[i] or tree.lca(a[i], r) == a[i]) {
                    continue;
                } else {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
