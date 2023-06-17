#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> dp(n+1, INT_MAX); dp[0] = 0;
    for (int i=1; i<10; i++) dp[i] = 1;

    for (int i=10; i<=n; i++) {
        int t = INT_MAX;
        for (int j=i; j; j/=10) t = min(t, dp[i - j%10]);
        dp[i] = 1 + t;
    }

    cout << dp[n];
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
