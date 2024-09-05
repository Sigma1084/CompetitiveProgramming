#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class DSU {
    const int n; // Number of nodes
    int nC; // Number of components
    std::vector<int> p;  // Parent
    std::vector<int> sz;  // Size of the component
public:
    DSU(int n): n(n), nC(n) { p.resize(n, -1); sz.resize(n, 1); }
    bool isLeader(int u) const { return p[u] < 0; }
    int size(int u) { return sz[find(u)]; }
    int numComp() const { return nC; }

    int find(int u) { 
        if (isLeader(u)) return u;
        return p[u] = find(p[u]);
    }

    bool merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) std::swap(u, v);
        p[v] = u; nC--;
        sz[u] += sz[v]; sz[v] = 0;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> h(n);
    for (auto &x: h) {
        cin >> x;
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (h[u] < h[v]) swap(u, v);
        // ensure h[u] >= h[v]
        g[u].push_back(v);
    }

    int nQ;
    cin >> nQ;

    vector<array<int, 5>> q(nQ);
    for (int i = 0; i < nQ; ++i) {
        auto &[idx, a, b, e, ans] = q[i];
        idx = i;
        cin >> a >> b >> e;
        --a; --b;
        // ensure h[u] <= h[v]
        // ensure e is the minimum energy we can go till
        e += h[a];
    }

    sort(q.begin(), q.end(), [&](auto &a, auto &b) {
        return a[3] < b[3];
    });

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](auto &a, auto &b) {
        return h[a] < h[b];
    });

    DSU dsu(n);
    int i = 0;  // Pointer for the query
    for (int i = 0, j = 0; i < n and j < nQ; ++i) {
        int u = ord[i];
        // We will have h[u] now
        for (auto v: g[u]) {
            dsu.merge(u, v);
        }
        while (j < nQ and (i == n - 1 or q[j][3] < h[ord[i+1]])) {
            auto &[idx, a, b, e, ans] = q[j];
            ans = dsu.find(a) == dsu.find(b);
            ++j;
        }
    }

    sort(q.begin(), q.end());

    for (auto [idx, a, b, e, ans]: q) {
        cout << (ans ? "YES" : "NO") << '\n';
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
