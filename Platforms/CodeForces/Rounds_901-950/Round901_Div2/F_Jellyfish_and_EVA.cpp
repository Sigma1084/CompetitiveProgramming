#include <bits/stdc++.h>
using namespace std;
using ld = long double;

constexpr int N = 5000;
array<vector<ld>, N + 1> f;

void preCompute() {
    // Odds
    for (int i = 1; i <= N; i += 2) {
        f[i].resize(i, 1);
        for (auto &x: f[i]) x /= i;
    }

    // Evens
    f[0].resize(0);
    for (int i = 2; i <= N; i += 2) {
        // Compute f[i] using f[i-2]
        f[i].resize(i);
        f[i][0] = 1;
        // From the next position onwards we need to
        for (int j = 1; j < i; ++j) {
            f[i][j] = 0;
            if (j-1 < i-2) {
                f[i][j] += (i-j-1) * f[i-2][j-1];
            }
            if (j-2 >= 0) {
                f[i][j] += (j-1) * f[i-2][j-2];
            }
        }
        for (auto &x: f[i]) x /= i;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> e(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        e[u].push_back(v);
    }

    vector<ld> dp(n);
    dp.back() = 1;

    for (int u = n-2; u >= 0; --u) {
        int d = e[u].size();
        dp[u] = 0;
        sort(e[u].begin(), e[u].end(), [&] (int x, int y) {
            return dp[x] > dp[y];
        });
        for (int i = 0; i < d; ++i) {
            dp[u] += dp[e[u][i]] * f[d][i];
        }
    }

    cout << fixed << setprecision(12) << dp[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    preCompute();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
