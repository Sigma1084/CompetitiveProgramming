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

    vector<string> b(n);
    for (auto &s: b) {
        cin >> s;
    }

    constexpr array<array<int, 2>, 4> de = {{
        {-1, 0}, {0, -1}, {0, 1}, {1, 0}
    }};

    auto isValid = [&] (int i, int j) {
        return 0 <= i and i < n and 0 <= j and j < m;
    };

    // First connect all of them
    DSU dsu(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[i][j] != 'W') continue;
            for (auto [di, dj]: de) {
                int ni = i + di, nj = j + dj;
                if (isValid(ni, nj) and b[ni][nj] == 'W') {
                    dsu.merge(i * m + j, ni * m + nj);
                }
            }
        }
    }

    // All merged components are connected
    // For every component add the neighboring black squares
    vector<set<array<int, 2>>> blacks(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[i][j] != 'W') continue;
            for (auto [di, dj]: de) {
                int ni = i + di, nj = j + dj;
                if (isValid(ni, nj) and b[ni][nj] == '.') {
                    blacks[dsu.find(i * m + j)].insert({ni, nj});
                }
            }
        }
    }

    // Now find the maximum size with a single black
    map<array<int, 2>, int> vals;
    for (int ij = 0; ij < n * m; ++ij) {
        if (blacks[ij].size() == 1) {
            vals[*blacks[ij].begin()] += dsu.size(ij);
        }
    }

    int ans = 0;
    for (const auto &[node, val]: vals) {
        ans = max(ans, val);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("ready_go_part_2_input.txt", "r", stdin);
    // freopen("ready_go_part_2_output.txt", "w", stdout);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }

    return 0;
}
