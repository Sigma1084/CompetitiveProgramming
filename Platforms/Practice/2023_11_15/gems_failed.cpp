#include <bits/stdc++.h>
using namespace std;

/**
 * Vanish the Gems: <br>
 *
 * You are given N gems
 *
 * You can destroy any gem in 1 second
 * Any gem gives w units of bad luck in t seconds
 *
 * Minimize the bad luck you get
 *
 * @param A (A.size() <= 2e3)
 */

int solve(vector<array<int, 2>> &A) {
    const int N = int(A.size());

    /**
     * dp[T][n] = {m, k}
     * where m is the min bad luck and k is the number of gems used
     * minimize m and maximize k
     */

    constexpr int INF = 2e9 + 9;
    vector dp(N + 1, vector(N + 1, pair<int, int>{INF, 0}));
    dp[0] = vector(N + 1, pair<int, int>{0, 0});
    for (int T = 1; T <= N; ++T) {
        for (int n = 1; n <= N; ++n) {
            // nth gem gives w units of bad luck in t seconds
            auto [t, w] = A[n-1];

            // Do not use the nth gem
            dp[T][n] = dp[T][n - 1];

            // Compute dp[T][n]
            if (t >= T) {
                // Case 1: the nth gem is enough to cover T seconds
                dp[T][n] = min(dp[T][n], {w, -1});
            } else {
                // Case 2: the nth gem is not enough to cover T seconds
                // We need to use the previous gems to cover T - t seconds
                dp[T][n] = min(dp[T][n],
                               {
                                  dp[T - t][n - 1].first + w,
                                  dp[T - t][n - 1].second - 1
                               });
            }
        }

        cerr << "dp = " << endl;
        for (auto &row : dp | std::views::drop(1)) {
            for (auto &val : row | std::views::drop(1)) {
                cerr << val.first << " " << -val.second << " | ";
            }
            cerr << endl;
        }
    }

    int ans = INF;
    for (int T = 1; T <= N; ++T) {
        // We can use maximum k gems to cover T seconds
        auto k = -dp[T][N].second;
        // We used k gems and destroyed T
        // We are left with N - T - k gems
        if (N - T - k <= 0) {
            // We destroyed all the gems
            ans = min(ans, dp[T][N].first);
        }
    }

    int totalBadLuck = 0;
    for (int n = 0; n < N; ++n) {
        totalBadLuck += A[n][1];
    }

    // If we cannot destroy all the gems
    if (ans == INF) {
        return 0;
    }

    return totalBadLuck - ans;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output_sol.txt", "w", stdout);

    vector<array<int, 2>> A;
    int ans;

    A = {{0, 10}, {0, 20}};
    ans = solve(A);
    cerr << "ans = " << ans << endl;
    assert(ans == 0);

    A = {{0, 10}, {1, 3}, {1, 4}, {1, 20}};
    ans = solve(A);
    cerr << "ans = " << ans << endl;
    assert(ans == 30);

    return 0;
}
