#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, k; cin >> n >> k;
	vector<int> f2(n), f5(n);

	for (int64_t i = 0, x; i < n; i++) {
		cin >> x;
		for (; x % 2 == 0; x /= 2) f2[i]++;
		for (; x % 5 == 0; x /= 5) f5[i]++;
	}

	constexpr int MAX_N = 200;
	constexpr int MAX_P5 = 25 * MAX_N;

	/**
	 * dp_i[j][k] = Maximum powers of 2 given that can be collected 
	 *   using the first i numbers by choosing j and
	 *   having k powers of 5
	 * 
	 * -1 if not possible
	 */

	vector<vector<int>> dp(k + 1, vector<int>(MAX_P5 + 1, -1));
	dp[0][0] = 0;  // 0 numbers, size 0 subset, power of 5^0

	for (int i = 0; i < n; i++) {
		for (int j = k - 1; j >= 0; j--) {
			for (int p5 = MAX_P5 - f5[i]; p5 >= 0; p5--) {
				// Here, we see how dp_i[j][p5] affects dp_{i+1} 
				//   when using the i-th number

				if (dp[j][p5] == -1) continue;  // No effect
				dp[j+1][p5 + f5[i]] = max(dp[j+1][p5 + f5[i]], dp[j][p5] + f2[i]);
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}

	return 0;
}
