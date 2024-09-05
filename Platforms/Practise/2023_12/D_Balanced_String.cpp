#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * dp[i][cnt0][cnt01]
 * Minimum number of operations to make s[0..i]
 * cnt0: number of 0s
 * cnt01: number of 01s
 * 
 * If we have a 0 at i, we can either:
 * 1. Make it 1 => We will be increasing cnt0 by nothing
 *          and number of 01s will increase by cnt0
 *          and also increase the number of operations by 1
 * 2. Keep it 0 => We will be increasing cnt0 by 1
 * 
 * If we have a 1 at i, we can either:
 * 1. Make it 0 => We will be increasing cnt0 by 1
 *         and also increase the number of operations by 1
 * 2. Keep it 1 => We will be increasing cnt01 by cnt0
 *          and number of 01s will increase by cnt0
 */
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;

    int n = int(s.size());
    constexpr int INF = 1e9;
    vector<vector<int>> dp(n + 1, vector<int>(n * n, INF));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        vector<vector<int>> ndp(n + 1, vector<int>(n * n, INF));
        for (int c0 = 0; c0 < n; ++c0) {
            for (int c01 = 0; c01 < n * n; ++c01) {
                if (dp[c0][c01] == INF) continue;
                if (s[i] == '0') {
                    ndp[c0][c01 + c0] = min(ndp[c0][c01 + c0], dp[c0][c01] + 1);
                    ndp[c0 + 1][c01] = min(ndp[c0 + 1][c01], dp[c0][c01]);
                } else {
                    ndp[c0 + 1][c01] = min(ndp[c0 + 1][c01], dp[c0][c01] + 1);
                    ndp[c0][c01 + c0] = min(ndp[c0][c01 + c0], dp[c0][c01]);
                }
            }
        }
        swap(dp, ndp);
    }

    int n0 = count(s.begin(), s.end(), '0');
    int req = n0 * (n - n0) / 2;

    cout << dp[n0][req] / 2 << '\n';

    return 0;
}
