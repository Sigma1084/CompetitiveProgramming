#include <bits/stdc++.h>
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

// USACO stuff
std::ifstream cin("time.in");
std::ofstream cout("time.out");

/**
 * dp[d][v] is the maximum of the moonies after the d-th day
 *   if she finishes on vertex v
 * 
 * dp[d+1][v] = max( dp[d][u] + M[v] - (Expense to travel the d-th day) )
 *    over vertices u when there is a path from u to v
 * 
 * Expense to travel the d-th day = c * (d^2 - (d-1)^2) = c * (2*d - 1)
 * 
 * The answer finally is the max(dp[d][0]) over all days
 * and the maximum number of days can be proved to be less than 1001
 * 
 * Time Complexity : O(n * m)
 * Space Complexity : O(n + m)
 */

constexpr int MAX_DAYS = 1001;  // Max number of days travelled is 1000

int main() {
	int n, m, c; cin >> n >> m >> c;

	// We follow 0-indexing for vertices

	std::vector<int> M(n);  // Moonies of i-th vertex is M[i]
	for (int &i: M) cin >> i;

	std::vector<std::array<int, 2>> E(m);  // Stores the edges as a list
	for (auto &[u, v]: E) {
		cin >> u >> v;
		u--; v--;  // Convert to 0 index
	}

	std::vector<int> dp(n, -1e9), dpOld(n, -1e9);
	dpOld[0] = 0;

	int ans = 0;

	for (int d = 1; d <= MAX_DAYS; d++) {
		for (auto [u, v]: E) {
			dp[v] = std::max(dp[v], dpOld[u] + M[v] - c * (2*d - 1));
		}
		ans = std::max(ans, dp[0]);
		dpOld = dp;
		dp.resize(n, -1e9);
	}

	cout << ans << std::endl;

	return 0;
}
