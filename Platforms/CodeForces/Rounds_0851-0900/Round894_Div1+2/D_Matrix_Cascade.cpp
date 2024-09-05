#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<string> b(n);
    
    for(string &s : b) {
        cin >> s;
    }

    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> change(n, vector<int>(n, 0));

    // Base case
    for (int j = 0; j < n; ++j) {
        if (b[0][j] == '1') {
            dp[0][j] = 1;
            change[0][j] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                dp[i][0] = dp[i-1][1] + change[i-1][0];
            } else if (j == n-1) {
                dp[i][n-1] = dp[i-1][n-2] + change[i-1][n-1];
            } else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1] 
                    - (i > 1 ? dp[i-2][j] : 0) + change[i-1][j];
            }
            if (dp[i][j] % 2 == 0 and b[i][j] == '1') {
                change[i][j] = 1;
                dp[i][j] += 1;
            } else if (dp[i][j] % 2 == 1 and b[i][j] == '0') {
                change[i][j] = 1;
                dp[i][j] += 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += change[i][j];
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
