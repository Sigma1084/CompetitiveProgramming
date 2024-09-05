#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = int(s.size());
    int ans = 0;

    vector dp(n, vector(n, 0));
    for (int i = n-1; i >= 0; --i) {
        for (int j = i+1; j < n; ++j) {
            if (s[i] != '?' and s[j] != '?' and s[i] != s[j]) {
                continue;
            }
            dp[i][j] = 1;
            if (j > i+1 and j+1 < n) {
                if (s[i+1] == '?' or s[j+1] == '?' or s[i+1] == s[j+1]) {
                    dp[i][j] = min(1 + dp[i+1][j+1], j - i);
                }
            }
            if (dp[i][j] == j - i) {
                ans = max(ans, 2 * dp[i][j]);
            }
        }
    }

    cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
