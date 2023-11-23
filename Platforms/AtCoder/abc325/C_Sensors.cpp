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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> b(n);
    for (auto &row: b) {
        cin >> row;
    }

    DSU dsu(n * m);

    int num = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            num += b[i][j] == '#';
        }
    }

    constexpr array<array<int, 2>, 8> dd = {{
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    }};

    auto isValid = [&] (int i, int j) {
        return 0 <= i and i < n and 0 <= j and j < m;
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[i][j] == '.') continue;
            for (auto [di, dj]: dd) {
                if (not isValid(i + di, j + dj)) continue;
                if (b[i + di][j + dj] == '#') {
                    dsu.merge(i * m + j, (i + di) * m + (j + dj));
                }
            }
        }
    }

    cout << dsu.numComp() - (n*m - num) << '\n';

    return 0;
}
