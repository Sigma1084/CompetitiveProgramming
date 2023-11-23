#include <bits/stdc++.h>
using namespace std;

/**
 * Vanish the Gems: <br>
 *
 * You are given N gems
 *
 * You can destroy any gem in 1 second
 * It takes t seconds to give c units of bad luck
 *
 * Minimize the bad luck you get
 *
 * @param A (A.size() <= 2e3)
 */

/**
 * 
 * In t seconds, we are spending c bad luck to destroy t + 1 gems
 * Earn N units of work with minimum cost
 */

int solve(vector<array<int, 2>> &A) {
    const int N = int(A.size());
    constexpr int INF = 2e9 + 5;

    /**
     * dp[w][n] := Min cost to get w units of work using gems 1..n
     */
    vector dp(N + 1, vector(N + 1, INF));

    // Minimum cost to get 0 units of work using no gems is 0
    for (int n = 1; n <= N; ++n) {
        auto [u, c] = A[n - 1];
        u++;
        dp[n][0] = 0;  // No work, no cost
        for (int w = 1; w <= N; ++w) {
            dp[n][w] = dp[n - 1][w];
            // How can we use the n-th gem
            if (w <= u) {
                // The n-th gem can do all the work
                dp[n][w] = min(dp[n][w], c);
            } else {
                // The n-th gem can not do all the work
                //   and we need to rely on previous gems
                dp[n][w] = min(dp[n][w], dp[n - 1][w - u] + c);
            }
        }
    }

    // dp[N][N] = Min cost to get N units of work using gems 1..N
    // Notice that dp[N][N] is always <= totalCost

    int totalCost = 0;
    for (auto [u, c]: A) {
        totalCost += c;
    }

    return totalCost - dp[N][N];
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output_sol.txt", "w", stdout);

    vector<array<int, 2>> A;
    int ans;

    A = {{0, 10}, {0, 20}};
    ans = solve(A);
    assert(ans == 0);

    A = {{0, 10}, {1, 3}, {1, 4}, {1, 20}};
    ans = solve(A);
    assert(ans == 30);

    return 0;
}
