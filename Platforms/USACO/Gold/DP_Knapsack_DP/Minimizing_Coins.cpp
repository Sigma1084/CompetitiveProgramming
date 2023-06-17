#include <bits/stdc++.h>
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

/**
 * @brief Explanation
 * 
 * Suppose dp[x] is the minimum number of coins required for money x
 * Initially, we set dp[i] = 1e9 since it can not be constructed
 * 
 * dp[x] = 1 + Minimum(dp[x-c]) where c is the cost of some coin
 * 
 * Required: dp[x]
 */

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, x;
	std::cin >> n >> x;

	std::vector<int> coins(n);
	for (int &c: coins) std::cin >> c;

	std::vector<int> dp(x + 1, 1e9);
	dp[0] = 0;  // 0 coins to construct 1 more 

	for (int c: coins) {
		for (int i = c; i <= x; i++) {
			dp[i] = std::min(dp[i], 1 + dp[i-c]);
		}
	}

	if (dp[x] > 1e7)
		dp[x] = -1;

	std::cout << dp[x] << std::endl;

	return 0;
}
