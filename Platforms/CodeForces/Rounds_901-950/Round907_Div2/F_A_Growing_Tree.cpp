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


void solve() {
    int nQ;
    cin >> nQ;

    // Number of nodes
    int n = 1;  // Root node
    vector<vector<int>> edges(n);

    vector<array<int, 3>> queries(nQ);
    for (auto &q: queries) {
        cin >> q[0] >> q[1];
        q[1]--;
        if (q[0] == 1) {
            n++;
            edges[q[1]].push_back(n - 1);
            edges.push_back({q[1]});
            q[2] = n - 1;
        } else {
            cin >> q[2];
        }
    }

    Tree tree;
    tree.buildET(edges);
    SegTree segTree(tree.tour.size());

    vector<ll> ans(n);

    reverse(queries.begin(), queries.end());
    for (auto [t, v, x]: queries) {
        if (t == 1) {
            // We are removing the node x and hence, store ONLY what is in x
            ans[x] = segTree.query(tree.in[x], tree.in[x]);
        } else {
            // We are adding x to all the nodes in the subtree of v
            segTree.update(tree.in[v], tree.out[v], x);
        }
    }
    ans[0] = segTree.query(tree.in[0], tree.in[0]);

    for (auto x: ans) {
        cout << x << ' ';
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
