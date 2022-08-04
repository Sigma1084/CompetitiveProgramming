#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);  // Ensures b >= a

    vector<vector<int>> dp(a+1, vector<int>(b+1, INT_MAX));
    for (int i=1; i<=a; i++) dp[i][i] = 0;

    for (int i=1; i<=a; i++) for (int j=1; j<=b; j++) {
        if (j <= i) { dp[i][j] = dp[j][i]; continue; }
        // Now, you have i * (j>i) Rectangle
        for (int cut=1; cut+cut <= i; cut++) 
            dp[i][j] = min(dp[i][j], 1 + dp[cut][j] + dp[i-cut][j]);
        for (int cut=1; cut+cut <= j; cut++)
            dp[i][j] = min(dp[i][j], 1 + dp[i][cut] + dp[i][j-cut]);
    }

    cout << dp[a][b];
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
