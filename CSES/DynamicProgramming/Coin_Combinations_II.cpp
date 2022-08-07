#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n, m; cin >> n >> m;  // m is money
    vector<int> a(n); for (auto &i: a) cin >> i;
    
    /**
     * @brief dp[num_of_coins_used][money]
     */
    vector<vector<ll>> dp(n+1, vector<ll>(m));
    for (int j=0; j<=m; j++) dp[0][j] = 1;

    
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
