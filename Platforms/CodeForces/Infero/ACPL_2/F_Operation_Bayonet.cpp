#include <bits/stdc++.h>
using namespace std;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t;
    cin >> n >> m >> t;

    vector<bool> isPres(n);
    for (int i = 0; i < t; ++i) {
        int x;
        cin >> x;
        --x;
        isPres[x] = true;
    }

    vector<vector<int>> e(n + m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        int mid = n + i;
        e[u].push_back(mid);
        e[mid].push_back(u);
        e[v].push_back(mid);
        e[mid].push_back(v);
    }

    int l, s;
    cin >> l >> s;
    --l; --s;

    isPres[l] = true;
    isPres[s] = true;

    vector<int> q;
    for (int u = 0; u < n; ++u) {
        if (isPres[u]) {
            q.push_back(u);
        }
    }

    DSU dsu(n + m);
    vector<bool> vis(n + m);
    int r = 0;
    while (dsu.find(l) != dsu.find(s) and !q.empty()) {
        ++r;
        vector<int> q2;
        for (int u: q) {
            vis[u] = true;
            for (int v: e[u]) {
                if (not vis[v]) {
                    dsu.merge(u, v);
                    q2.push_back(v);
                }
            }
        }

        swap(q, q2);
    }

    if (dsu.find(l) != dsu.find(s)) {
        cout << -1 << '\n';
    } else {
        cout << r << '\n';
    }

    return 0;
}
