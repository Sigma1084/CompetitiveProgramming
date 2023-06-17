#include <bits/stdc++.h>

// std::ifstream cin("feast.in");
// std::ofstream cout("feast.out");
using std::cout; using std::cin;

int main() {
	int t, a, b; cin >> t >> a >> b;

	std::vector<int> dp(t + 1);
	for (int i = 1; i <= t; i++) {
		if (i >= a) dp[i] = std::max(dp[i], dp[i-a] + a);
		if (i >= b) dp[i] = std::max(dp[i], dp[i-b] + b);
	}

	int ans = 0;
	for (int i = 1; i <= t; i++) {
		ans = std::max(ans, dp[i]);
		ans = std::max(ans, dp[i]/2 + dp[t - dp[i] + dp[i]/2]);
	}

	cout << ans;

	return 0;
}
