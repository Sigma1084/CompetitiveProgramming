#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        --p[i];
        g[p[i]].push_back(i);
    }

    string s;
    cin >> s;

    /**
     * dp[u][0] := Nothing
     * dp[u][1] := Only type 1 (P)
     * dp[u][2] := Only type 2 (S)
     */
    vector<array<int, 3>> dp(n);
    for (int u = n - 1; u >= 0; --u) {
        dp[u][0] = (s[u] != 'C');
        dp[u][1] = (s[u] == 'S') * INF;
        dp[u][2] = (s[u] == 'P') * INF;
        for (auto v: g[u]) {
            // We can not let anything go up
            dp[u][0] += dp[v][0];
            dp[u][1] += min({dp[v][1], dp[v][0], 1 + dp[v][2]});
            dp[u][2] += min({dp[v][2], dp[v][0], 1 + dp[v][1]});
        }
        dp[u][0] = min({dp[u][0], dp[u][1] + 1, dp[u][2] + 1});
    }

    cout << min({dp[0][0], dp[0][1], dp[0][2]});
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
