#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

/**
 * dp[mask] := showtime
 */
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	freopen("movie.in", "r", stdin);
	freopen("movie.out", "w", stdout);

	int n, l; cin >> n >> l;
	vector<int> d(n), c(n);
	vector<vector<int>> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> d[i] >> c[i];
		s[i].resize(c[i]);
		for (int &x : s[i]) cin >> x;
	}

	vector<int> dp(1 << n);
	dp[0] = 0;  // showtime for empty set

	for (int mask = 1; mask < (1 << n); ++mask) {
		for (int i = 0; i < n; i++) {
			if (!(mask & (1 << i))) continue;  // i not in mask
			int prev = mask ^ (1 << i);  // remove i from mask
			auto it = upper_bound(s[i].begin(), s[i].end(), dp[prev]);  // first showtime after dp[prev]
			if (it == s[i].begin()) continue;  // no showtime before dp[prev]
			--it;  // first showtime <= dp[prev]
			dp[mask] = max(dp[mask], *it + d[i]);  // showtime for mask
			dp[mask] = min(dp[mask], l);  // showtime <= l
		}
	}

	int ans = n + 1;
	for (int mask = 0; mask < (1 << n); ++mask) {
		if (dp[mask] == l) {
			ans = min(ans, (int) bitset<32>(mask).count());
		}
	}

	if (ans == n + 1) ans = -1;
	cout << ans << '\n';

	return 0;
}
