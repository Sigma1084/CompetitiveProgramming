#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &i: a) cin >> i;
    vector<ll> s(n+1); s[0] = 0; 
    for (int i=0; i<n; i++) s[i+1] = s[i] + a[i];

    /**
     * @brief [start_index][end_index]
     * Answer from start_index to end_index 
     */
    vector<vector<ll>> dp(n, vector<ll>(n));
    
    for (int i=0; i<n; i++) dp[i][i] = a[i];

    for (int d=1; d<n; d++) {
        for (int i=0; i+d<n; i++) {
            ll ci = (s[i+d+1] - s[i+1]) + a[i] - dp[i+1][i+d];
            ll cd = (s[i+d] - s[i]) + a[i+d] - dp[i][i+d-1];
            dp[i][i+d] = max(ci, cd);
        }
    }

    cout << dp[0][n-1];
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
