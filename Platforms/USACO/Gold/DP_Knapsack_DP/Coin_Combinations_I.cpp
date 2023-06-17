#include <bits/stdc++.h>

constexpr int P = 1'000'000'007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, x;
	std::cin >> n >> x;

	std::vector<int> coins(n);
	for (int &c: coins) std::cin >> c;
	std::sort(coins.begin(), coins.end());

	// dp[x] := Number of ways of generating money sum x using the given coins
	std::vector<int> dp(x + 1);
	dp[0] = 1;  // There is one way to construct the cost 0

	for (int i = 1; i <= x; i++) {
		for (int c: coins) {
			if (c > i) break;
			dp[i] += dp[i-c];
			dp[i] %= P;
		}
	}

	std::cout << dp[x] << std::endl;

	return 0;
}
