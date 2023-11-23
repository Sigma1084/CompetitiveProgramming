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

    int a, b;
    cin >> a >> b;
    --a; --b;

    DSU dsu1(n), dsu2(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        --u; --v;
        if (u != a and v != a) dsu1.merge(u, v);
        if (u != b and v != b) dsu2.merge(u, v);
    }

    cout << 1LL * (n - 1 - dsu1.size(b)) * (n - 1 - dsu2.size(a));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
