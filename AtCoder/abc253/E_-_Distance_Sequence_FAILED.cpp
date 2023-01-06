#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve() {
    const int MOD = 998244353;
    int n, m, k; cin >> n >> m >> k;

    /**
     * @brief dp[end_index][end_number]
     */

    vector<vector<ll>> dp(n, vector<ll>(m+1, 0));
    for (int i=1; i<=m; i++) dp[0][i] = 1;
    
    for (int i=1; i<n; i++) {
        vector<ll> dps(m+1); dps[0] = dp[i-1][0];
        for (int j=1; j<=m; j++) 
            dps[j] = dps[j-1] + dp[i-1][j], dps[j] %= MOD;

        for (int e=1; e<=m; e++) {
            dp[i][e] += dps[max(0, e-k)];
            dp[i][e] += MOD + dps[m] - dps[min(m, e+k-1)];
            dp[i][e] %= MOD;
        }
    }
    
    ll ans = 0;
    for (int e=1; e<=m; e++)
        ans += dp[n-1][e], ans %= MOD;
    
    cout << ans;
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
