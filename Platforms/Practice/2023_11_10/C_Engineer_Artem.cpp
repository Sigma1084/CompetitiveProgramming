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

constexpr array<pair<int, int>, 8> gridIter = {{
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
}};

void solve() {
    int n, m;
    cin >> n >> m;

    vector a(n, vector<int>(m));
    DSU dsu(n * m);

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (abs(a[i-1][j] - a[i][j]) <= 1) {
                dsu.merge(i * m + j, (i-1) * m + j);
            }
            if (abs(a[i][j-1] - a[i][j]) <= 1) {
                dsu.merge(i * m + j, i * m + j - 1);
            }
        }
    }

    map<int, vector<pair<int, int>>> comps;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            comps[dsu.find(i * m + j)].emplace_back(i, j);
        }
    }

    // Now for every cell, we know which cells are in the same component
    vector vis(n, vector(m, false));
    for (const auto &[leader, comp]: comps) {
        sort(comp.begin(), comp.end(),
        [&a](const auto &lhs, const auto &rhs) {
            return a[lhs.first][lhs.second] < a[rhs.first][rhs.second];
        });
        for (auto [i, j]: comp) {
            if (vis[i][j]) continue;
            vis[i][j] = true;
            // TODO: Finish this
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
