#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int s, n; std::cin >> s >> n;

	/**
	 * When we get a new item, put the value, num_items in
	 * the vector of items with the same weight.
	 */

	std::vector<std::vector<std::array<int, 2>>> items_by_weight(s + 1);

	for (int i = 0, v, w, k; i < n; ++i) {
		std::cin >> v >> w >> k;
		items_by_weight[w].push_back({v, k});
	}

	/**
	 * Sort the items of the same weight in descending order of value.
	 */
	for (auto &v : items_by_weight) {
		std::sort(v.begin(), v.end(), std::greater<>());
	}

	/**
	 * dp[x] = Maximum Profit with Weight x after using items of weight 1 to w
	 * dpOld[x] stores the corresponding values before using items of weight w
	 */
	std::vector<int64_t> dp(s + 1, 0), dpOld;

	for (int w = 1; w <= s; ++w) {
		auto &vals = items_by_weight[w];
		if (vals.empty()) continue;  // If there are no items of weight w, skip

		dpOld = dp;  // Store the values of dp before using items of weight w
		int64_t profit = 0;  // Profit of the items of weight w
		int totW = 0;  // Total Weight of the items of weight w

		for (std::size_t i = 0; i < vals.size(); ) {
			auto &[v, k] = vals[i];
			if (k == 0) { ++i; continue; }

			profit += v;  // Add the value of the item
			totW += w;  // Weight of the items of weight w increases by w
			--k;  // Current item can not be used again

			if (totW > s) break;  // If the total weight exceeds s, stop

			for (int x = totW; x <= s; x++) {
				dp[x] = std::max(dp[x], dpOld[x - totW] + profit);
			}
		}
	}

	std::cout << dp[s] << '\n';

	return 0;
}
