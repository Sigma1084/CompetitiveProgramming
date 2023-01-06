#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

vector<int> dp[2];

void solve() {
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    string s[2]; s[0] = "", s[1] = "";
    for (int i = 0; i < n; i++) {
        if (s1[i] == '1' or s2[i] == '1') {
            s[0].push_back(s1[i]);
            s[1].push_back(s2[i]);
        }
    }
    n = s[0].size();
    if (n == 0) {
        cout << 0;
        return;
    }

    dp[0].resize(n+1);
    dp[1].resize(n+1);

    dp[0][n] = dp[1][n] = 0;
    dp[0][n-1] = dp[1][n-1] = (s[0][n-1] == '1') + (s[1][n-1] == '1');
    for (int c = n-2; c >= 0; c--) {
        for (int r = 0; r < 2; r++) {
            if ((s[r][c+1] == '1') or (s[1-r][c] == '1')) {
                // Can only take one of the 2 paths anyway
                dp[r][c] = max(dp[r][c+1], 1 + (s[1-r][c+1] == '1') + dp[1-r][c+2]);
            } else {
                // Go front and decide
                dp[r][c] = dp[r][c+1];
            }
            dp[r][c] += (s[r][c] == '1');
        }
    }

    // for (int r = 0; r < 2; r++) {
    //     for (int c = 0; c < n; c++) {
    //         cout << dp[r][c] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[0][0];
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

