#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

constexpr int P = 1'000'000'007;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m; cin >> n >> m;

	/**
	 * We want a huge array of size 2*m
	 * The number of such arrays in ascneding order is the answer
	 * 
	 * dp[n][m] := Number of characters
	 * 
	 * i = 3
	 * j = 4
	 * 
	 * no 3s: i = 2 j = 4          =>   _ _ _ _
	 * exactly 1 3s: i = 2 j = 3   =>   _ _ _ 3
	 * exactly 2 3s: i = 2 j = 2   =>   _ _ 3 3
	 * exactly 3 3s: i = 2 j = 1   =>   _ 3 3 3
	 * exactly 4 3s: i = 2 j = 0   =>   3 3 3 3
	 */

	vector<vector<int>> dp(n + 1, vector<int>(2 * m + 1));
	for (int i = 0; i <= n; i++) dp[i][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2 * m; j++) {
			for (int k = 0; k <= j; k++) {
				// Corresponds to having numbers in (1, i-1) in the first k 
				// and the rest of them as i's
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= P;
			}
		}
	}

	cout << dp[n][2*m];

	return 0;
}
