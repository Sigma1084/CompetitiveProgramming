#include <bits/stdc++.h>
using namespace std;

/**
 * Consider a n bit integer
 * Suppose n = 5 (0-indexing)
 * dp[10001] := Number of ways when men 0 and 1
 *   are paired with women 0 and 4
 * We need dp[11111]
 */
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	constexpr int P = 1'000'000'007;

	int n; cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	for (auto &v: arr) for (auto &x: v) cin >> x;

	vector<int> dp(1 << n);
	dp[0] = 1;

	for (int mask = 0; mask < (1 << n) - 1; mask++) {
		int m = bitset<32>(mask).count();

		// Add any undone women to the dps above
		for (int w = 0; w < n; w++) {
			if (!(mask & (1 << w)) and arr[m][w]) {
				(dp[mask + (1 << w)] += dp[mask]) %= P;
			}
		}
	}
	
	cout << dp[(1 << n) - 1] << '\n';
}
