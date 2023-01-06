#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;
const ll INF = 1e16;

#define V vector

/**
 * @brief Ffloyd Warshall algorithm
 * https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
 */

void solve() {
    int n, m, q; cin >> n >> m >> q;
    V<V<ll>> dp(n + 1, V<ll>(n + 1, INF));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = dp[v][u] = min(dp[u][v], (ll)w);
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    /**
     * @brief dp[i][j] = minimum distance from i to j
     */
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v;
        cout << (dp[u][v] != INF ? dp[u][v] : -1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

