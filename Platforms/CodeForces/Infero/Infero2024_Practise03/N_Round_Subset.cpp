#include <bits/stdc++.h>
using std::vector;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// Choose a subset of size k, 1 <= k <= n
	int n, k; std::cin >> n >> k;

	/**
	 * Store the number of factors of 2 and 5 for each number.
	 */
	vector<std::array<int, 2>> factors(n);
	for (int64_t i = 0, temp; i < n; i++) {
		std::cin >> temp;
		while (temp % 2 == 0) {
			temp /= 2;
			factors[i][0]++;
		}
		while (temp % 5 == 0) {
			temp /= 5;
			factors[i][1]++;
		}
	}

	/**
	 * Max Answer is 3600
	 * Maximum power of 2 in a number 18 / log_10(2) < 60
	 * Maximum power of 5 in a number 18 / log_10(5) < 26
	 */


	/**
	 * For every i, we calculate the following 
	 * 
	 * dp[j][p5] = Maximum number of factors of 2 we can collect from
	 *             the first i numbers taking j of them having exactly
	 *             pw5 powers of 5
	 */


	constexpr int MAX_POW = 25 * 200;
	vector<vector<int>> dp(k + 1, vector<int>(MAX_POW + 1, -1)), dpOld;

	// It is only possible to construct when pw5 = 0
	dp[0][0] = 0;

	/**
	 * Sort with powers of 5 ascending and powers of 2 descending
	 */
	std::sort(factors.begin(), factors.end(), [](auto a, auto b) {
		if (a[1] == b[1]) return a[0] > b[0];
		return a[1] < b[1];
	});


	for (int i = 1; i <= n; ++i) {
		dpOld = dp;
		// Considering the first i numbers

		// Factors in the i-th element
		auto [f2, f5] = factors[i-1];

		for (int j = 1; j <= std::min(i, k); ++j) {
			// Not taking the i-th element
			dp[j] = dpOld[j];  // Equal to the previous dp

			// Taking the i-th element
			for (int pw5 = 0; pw5 + f5 <= MAX_POW; pw5++) {
				if (dpOld[j-1][pw5] != -1)
					dp[j][pw5 + f5] = std::max(dp[j][pw5 + f5], dpOld[j-1][pw5] + f2);
			}
		}
	}

	int ans = 0;
	for (int pw5 = 0; pw5 <= MAX_POW; pw5++) {
		if (dp[k][pw5] != -1)
			ans = std::max(ans, std::min(pw5, dp[k][pw5]));
	}

	std::cout << ans;

	return 0;
}
