#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

void solve() {
    int n, M; cin >> n >> M;
    vector<int> a(n); for (auto &i: a) cin >> i;
    sort(a.begin(), a.end());

    /**
     * @brief dp[coins_used][money_required]
     */

    vector<vector<int>> dp(n+1, vector<int>(M+1, 0)); dp[0][0] = 1;

    for (int nc=1; nc<=n; nc++) for(int m=0; m<=M; m++) {
        // Have nc coins to make money m
        dp[nc][m] = dp[nc-1][m];
        if (m >= a[nc-1]) dp[nc][m] += dp[nc][m-a[nc-1]];
        dp[nc][m] %= MOD;
    }

    cout << dp[n][M];
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
