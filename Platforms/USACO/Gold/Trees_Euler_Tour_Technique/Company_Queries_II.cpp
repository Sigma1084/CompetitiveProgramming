#include <bits/stdc++.h>

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

public:
    /**
     * @brief Default constructor
     */
    SparseTable() = default;

    /**
     * @brief Default copy constructor
     */
    SparseTable(const SparseTable<T> &st) = default;

    /**
     * @brief Construct a new Sparse Table object
     * @tparam V The type of the elements in the vector
     * @param a Vector to be processed
     * @param merge The merge function
     */
    template<class V>
    SparseTable(const std::vector<V> &a, Merger merge) {
        build(a, merge);
    }

    /**
     * @brief Build the sparse table
     * @param a Vector to be processed
     * @tparam V The type of the elements in the vector
     */
    template<class V>
    void build(const std::vector<V> &a, Merger _merge) {
        merge = _merge;
        K = std::log2(a.size());

        st.resize(K + 1);
        std::size_t n = a.size();
        st[0].resize(n);
        std::copy(a.begin(), a.end(), st[0].begin());

        for (int i = 1; i <= K; ++i) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j < static_cast<int>(n - (1 << i) + 1); ++j) {
                st[i][j] = merge(
                    st[i - 1][j],
                    st[i - 1][j + (1 << (i - 1))]
                );
            }
        }
    }

    /**
     * @brief Get the sparse table object for debugging
     * @return A const reference to the sparse table
     */
    const std::vector<std::vector<T>>& operator () () const {
        return st;
    }

    /**
     * @brief Range Query in O(1)
     * @param l Left index of the query
     * @param r Right index of the query
     * @return The result of the query
     */
    [[maybe_unused]] [[nodiscard]]
    T query(int l, int r) {
        if (l > r) {
            throw std::invalid_argument("l must be <= r");
        } else {
            int k = std::log2(r - l + 1);
            return merge(st[k][l], st[k][r - (1 << k) + 1]);
        }
    }
};


/**
 * @brief Euler Tour of a tree
 * @details Euler Tour is the order in which the nodes of a tree are visited
 * in a DFS traversal.
 */
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

    /**
     * @brief Depth First Search to build the Euler Tour
     * @param u The current node
     */
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

    /**
     * @brief Build the Euler Tour
     * @param _edges 
     * @param _root 
     */
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

    /**
     * @brief Get the size of the tree
     * @return size of the tree
     */
    constexpr int size () const {
        return n;
    }

    const std::vector<std::vector<int>>& e = edges;

    const std::vector<int> &p = parent;
    const std::vector<int> &d = depth;
    const std::vector<int> &sz = subtreeSize;

    const std::vector<int> &tour = _tour;
    const std::vector<int> &in = _in;
    const std::vector<int> &out = _out;
};


/**
 * @brief Lowest Common Ancestor using Euler Tour
 * @details Uses RMQ on Euler Tour to find the LCA of two nodes
 */
class LCATree: public Tree {
    SparseTable<int> rmq;
public:
    using Tree::Tree;

    /**
     * @brief Build the LCA table
     * @details Uses RMQ on Euler Tour to build the LCA table
     */
    void buildLCA() {
        if (root == -1) {
            throw std::runtime_error("Tree not built yet");
        } else if (rmq().empty()) {
            rmq.build(_tour, [&](int u, int v) -> int {
                return depth[u] < depth[v] ? u : v;
            });  // Range Min Query on depth
        }
    }

    /**
     * @brief Returns the Least Common Ancestor of two nodes
     * @param u
     * @param v
     * @return least common ancestor of u and v
     */
    int lca(int u, int v) {
        if (rmq().empty()) buildLCA();
        return rmq.query(std::min(_in[u], _in[v]),
            std::max(_out[u], _out[v]));
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, nQ;
    std::cin >> n >> nQ;

    std::vector<std::vector<int>> e(n);
    for (int u = 1, p; u < n; u++) {
        std::cin >> p; p--;
        e[u].push_back(p);
        e[p].push_back(u);
    }

    LCATree t;
    t.buildET(e);
    t.buildLCA();

    for (int a, b; nQ--; ) {
        std::cin >> a >> b;
        std::cout << t.lca(a - 1, b - 1) + 1 << '\n';
    }

    return 0;
}
