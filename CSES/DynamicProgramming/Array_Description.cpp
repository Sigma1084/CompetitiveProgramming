#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for (auto &i: a) cin >> i;
    const int MOD = 1e9 + 7;

    // dp[end][val] := Number of paths from index 0 to index end containing val
    // Following 1 indexing, 1 <= end <= n and 1 <= val <= m
    vector<vector<ll>> dp(n, vector<ll>(m+1, 0));
    if (a[0] == 0) dp[0] = vector<ll>(m+1, 1); 
    else dp[0][a[0]] = 1;

    for (int i=1; i<n; i++) {
        if (a[i] == 0) {
            for (int j=1; j<=m; j++) {
                // Case where a[j] is made to be 0
                for (int s=max(1, j-1); s<=min(m, j+1); s++)
                    dp[i][j] += dp[i-1][s], dp[i][j] %= MOD;
            }
        } else {
            for (int s=max(1, a[i]-1); s<=min(m, a[i]+1); s++)
                dp[i][a[i]] += dp[i-1][s], dp[i][a[i]] %= MOD;
        }
    }

    ll ans = 0;
    if (a[n-1] == 0) {
        for (int i=1; i<=m; i++) {
            ans += dp[n-1][i];
            ans %= MOD;
        }
    } else {
        ans = dp[n-1][a[n-1]];
    }

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
