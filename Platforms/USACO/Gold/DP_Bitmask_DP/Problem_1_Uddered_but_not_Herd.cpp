#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

/**
 * For a subset S, store { ans, weight_in_last_subset } 
 */
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int &y: a) cin >> y;

	vector<array<int, 2>> dp(1 << n, {n + 1, 0});
	dp[0] = { 0, 0 };

	for (int mask = 1; mask < 1 << n; mask++) {
		for (int i = 0; i < n; i++) {
			if (not(mask & (1 << i))) continue;
			auto option = dp[mask ^ (1 << i)];
			if (option[1] + a[i] <= x) {
				option[1] += a[i];
			} else {
				option[0]++;
				option[1] = a[i];
			}
			dp[mask] = min(dp[mask], option);
		}
	}

	cout << dp[1 << n - 1][0];

	return 0;
}
