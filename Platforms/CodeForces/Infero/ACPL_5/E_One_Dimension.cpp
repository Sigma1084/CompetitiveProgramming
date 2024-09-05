#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;

    int n = int(s.size());

    int C;
    cin >> C;

    /**
     * i: Position (100)
     * c: Changes used (50)
     * d: Direction (0: proper, 1: reverse) (2)
     * dp[i+1][c][d]: Max score
     */
    constexpr int MIN = -1e9;
    vector dp(n + 1, vector(C + 1, vector(2, MIN)));
    dp[0][0][0] = 0;

    // Change 0, we update first
    for (int i = 0, sc = 0, d = 0; i < n; ++i) {
        if (s[i] == 'F') {
            sc += (d == 0 ? 1 : -1);
        } else {
            d ^= 1;
        }
        if (sc == 0) {
            d = 0;
        }
        dp[i+1][0][d] = sc;
        dp[i+1][0][d^1] = -sc;
    }

    for (int i = 0; i < n; ++i) {
        for (int c = 1; c <= C; ++c) {
            if (s[i] == 'F') {
                // Not changing
                dp[i+1][c][0] = dp[i][c][0] + 1;
                dp[i+1][c][1] = dp[i][c][1] - 1;

                // Changing
                dp[i+1][c][0] = max(dp[i+1][c][0], dp[i][c-1][1]);
                dp[i+1][c][1] = max(dp[i+1][c][1], dp[i][c-1][0]);
            } else {
                // Not changing
                dp[i+1][c][0] = dp[i][c][1];
                dp[i+1][c][1] = dp[i][c][0];

                // Changing
                dp[i+1][c][0] = max(dp[i+1][c][0], dp[i][c-1][0] + 1);
                dp[i+1][c][1] = max(dp[i+1][c][1], dp[i][c-1][1] - 1);
            }
        }
    }

    int ans = MIN;
    for (int c = C; c >= 0; c -= 2) {
        for (int d = 0; d < 2; ++d) {
            ans = max(ans, dp[n][c][d]);
        }
    }
    cout << ans << '\n';

    return 0;
}
