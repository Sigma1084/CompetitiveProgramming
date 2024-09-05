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

    vector<string> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    DSU dsu(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.') continue;
            if (i + 1 < n and a[i+1][j] == '#') {
                dsu.merge(i * m + j, (i + 1) * m + j);
            }
            if (j + 1 < m and a[i][j+1] == '#') {
                dsu.merge(i * m + j, i * m + j + 1);
            }
        }
    }

    vector<int> er(n), ec(m);
    vector<int> rm(n * m, n), rM(n * m), cm(n * m, m), cM(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.') {
                er[i]++;
                ec[j]++;
            } else {
                int node = dsu.find(i * m + j);
                rm[node] = min(rm[node], i - 1);
                rM[node] = max(rM[node], i + 1);
                cm[node] = min(cm[node], j - 1);
                cM[node] = max(cM[node], j + 1);
            }
        }
    }
    for (auto &x: rm) {
        if (x == -1) x = 0;
    }
    for (auto &x: rM) {
        if (x == n) x = n - 1;
    }
    for (auto &x: cm) {
        if (x == -1) x = 0;
    }
    for (auto &x: cM) {
        if (x == m) x = m - 1;
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    auto f = [&](int r1, int r2, int c1, int c2, int val) {
        dp[r2 + 1][c2 + 1] += val;
        dp[r1][c1] += val;
        dp[r1][c2 + 1] -= val;
        dp[r2 + 1][c1] -= val;
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.' or dsu.find(i * m + j) != i * m + j) {
                continue;
            }
            int r1 = rm[i * m + j], r2 = rM[i * m + j];
            int c1 = cm[i * m + j], c2 = cM[i * m + j];
            int sz = dsu.size(i * m + j);
            f(r1, r2, 0, m - 1, sz);
            f(0, n - 1, c1, c2, sz);
            f(r1, r2, c1, c2, -sz);
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        dp[i][m] += dp[i + 1][m];
    }
    for (int j = m - 1; j >= 0; --j) {
        dp[n][j] += dp[n][j + 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; -- j) {
            dp[i][j] += dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = max(ans, dp[i+1][j+1] + er[i] + ec[j] - (a[i][j] == '.'));
        }
    }

    cout << ans;
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
