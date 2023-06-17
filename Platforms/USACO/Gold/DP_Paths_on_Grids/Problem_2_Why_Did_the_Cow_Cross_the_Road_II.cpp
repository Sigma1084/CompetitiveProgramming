#include <bits/stdc++.h>
using ll = int64_t;
using std::vector;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::ifstream cin("nocross.in");
	std::ofstream cout("nocross.out");
	// using std::cin, std::cout;

	int n; cin >> n;
	std::vector<int> a(n), b(n);
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;

	/**
	 * dp[i][j] := Number of ways of crossing the road with
	 *  i fields on the left side
	 *  j fields on the right side
	 */

	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool ok = abs(a[i] - b[j]) <= 4;
			dp[i][j] = std::max(i ? dp[i - 1][j] : 0, j ? dp[i][j - 1] : 0);
			if (ok) dp[i][j] = std::max(dp[i][j], 1 + (i and j ? dp[i - 1][j - 1] : 0));
		}
	}

	cout << dp[n - 1][n - 1];

	return 0;
}
