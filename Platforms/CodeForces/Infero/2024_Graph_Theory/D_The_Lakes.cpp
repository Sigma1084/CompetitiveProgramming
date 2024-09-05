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

    vector a(n, vector(m, 0));
    for (auto &x: a) {
        for (auto &y: x) {
            cin >> y;
        }
    }

    DSU dsu(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0) continue;
            if (i and a[i-1][j]) dsu.merge(i*m + j, (i-1)*m + j);
            if (j and a[i][j-1]) dsu.merge(i*m + j, i*m + j-1);
        }
    }

    vector<int> comp(n * m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            comp[dsu.find(i*m + j)] += a[i][j];
        }
    }

    cout << *max_element(comp.begin(), comp.end());
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
