#include <bits/stdc++.h>
using namespace std;

// template <int N>
// struct ModInt {
//     int v = 0;
//     ModInt<N>() = default();
//     ModInt<N>(int n): v(n%N);
//     ModInt<N> operator += (int n) { 
//         n %= N; if ()
//     }
// }

void solve() {
    int n; cin >> n;
    vector<string> b(n); for (auto &s: b) cin >> s;
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    const int MOD = 1e9 + 7;

    if (b[0][0] == '*') {
        cout << 0;
        return;
    }

    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        if (i == 0 and j == 0) { dp[0][0] = 1; continue; }
        if (b[i][j] != '.') continue;
        if (i-1 >= 0 and b[i][j] == '.') dp[i][j] += dp[i-1][j];
        if (j-1 >= 0 and b[i][j] == '.') dp[i][j] += dp[i][j-1];
        dp[i][j] %= MOD;
    }

    cout << dp[n-1][n-1];
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
