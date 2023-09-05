#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct EulerTour {
    const int n;
    int root;
    std::vector<int> p;  // parent
    std::vector<int> tour;  // euler tour
    std::vector<int> in;  // in[u] = index of u in the euler tour
    std::vector<int> out;  // out[u] = last index of the subtree of u

    EulerTour(const std::vector<std::vector<int>> &graph, int _root = 0):
            n(graph.size()) {

        tour.reserve(n);
        in.resize(n);
        out.resize(n);
        p.resize(n);

        std::function<void(int)> dfs = [&](int u) -> void {
            tour.push_back(u);
            in[u] = tour.size() - 1;
            for (auto v: graph[u]) {
                if (v == p[u]) continue;
                p[v] = u;
                dfs(v);
            }
            out[u] = tour.size() - 1;
        };

        root = _root;
        p[root] = root;
        dfs(root);
    }
};


template <typename T>
class LazySegmentTreeAddition {
    int n;
    std::vector<T> tree;
    std::vector<T> lazy;

    virtual void push(int node, int nL, int nR) {
        if (lazy[node] == 0) return;  // Nothing to push
        tree[node] += lazy[node] * (nR - nL + 1);

        if (nL != nR) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    virtual T query(int node, int nL, int nR, int l, int r) {
        push(node, nL, nR);
        if (nR < l or r < nL) return 0;  // node out of range
        if (l <= nL and nR <= r) return tree[node];  // perfect overlap
        int m = (nL + nR) / 2;
        return query(node * 2, nL, m, l, std::min(r, m)) +
            query(node * 2 + 1, m + 1, nR, std::max(l, m + 1), r);
    }

    virtual void update(int node, int nL, int nR, T val, int l, int r) {
        if (nR < l or r < nL) return;  // node out of range

        // Perfect overlap.
        if (l <= nL and nR <= r) {
            lazy[node] += val;
            return;
        }

        // Partial overlap.
        tree[node] += val * (std::min(r, nR) - std::max(l, nL) + 1);

        // Propagate the update to the children
        int m = (nL + nR) / 2;
        update(node * 2, nL, m, val, l, r);
        update(node * 2 + 1, m + 1, nR, val, l, r);
    }

public:
    LazySegmentTreeAddition(): n(0) {};

    LazySegmentTreeAddition(int _n) {
        reinitialize(_n);
    };

    template<class U>
    LazySegmentTreeAddition(const std::vector<U> &v) {
        reinitialize(v.size());
        for (int i = 0; i < int(v.size()); i++) {
            tree[i + n] = v[i];
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

    void reinitialize(int _n) {
        if (_n < 2) {
            n = _n;
        } else {
            n = 2 << std::__lg(std::max(1, _n - 1));
        }
        tree.resize(2 * n, T());
        lazy.resize(2 * n, T());
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    void addInRange(int l, int r, T val) {
        update(1, 0, n - 1, val, l, r);
    }
};
int u, v; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, nQ; cin >> n >> nQ;
    vector<int> a(n);
    vector<vector<int>> g(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    EulerTour et(g);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[et.in[i]] = a[i];
    }

    LazySegmentTreeAddition<ll> st(b);

    for (int t, s, x, i; nQ; nQ--) {
        cin >> t >> s; s--;
        i = et.in[s];
        if (t == 1) {
            cin >> x;
            st.addInRange(i, i, x - b[i]);
            b[i] = x;
        } else {
            cout << st.query(et.in[s], et.out[s]) << '\n';
        }
    }

    return 0;
}
