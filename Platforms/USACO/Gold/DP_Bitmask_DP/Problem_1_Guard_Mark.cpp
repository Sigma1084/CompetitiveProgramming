#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);

	int n, H; cin >> n >> H;

	vector<array<int, 3>> cows(n);  // [h, w, s]
	for (auto &[h, w, s]: cows) cin >> h >> w >> s;

	sort(cows.begin(), cows.end(), [](auto &a, auto &b) {
		return a[2] > b[2];
	});  // strength descending

	vector<ll> dp(1 << n, -1);  // dp[mask] = max strength of a subset of cows
	ll ans = -1;

	dp[0] = 1e18;  // base case
	for (int mask = 0, i; mask < (1 << n); mask++) {
		ll hS = 0;  // Height of the subset

		for (i = 0; i < n; i++) {
			if (!(mask & (1 << i))) continue;
			// cow i is in the subset
			const auto &[h, w, s] = cows[i];
			hS += h;

			// we will now be placing cow i at the top
			dp[mask] = max(dp[mask], min(dp[mask ^ (1 << i)] - w, ll(s)));
		}

		if (hS >= H) ans = max(ans, dp[mask]);
	}

	if (ans == -1) cout << "Mark is too tall\n";
	else cout << ans << '\n';

	return 0;
}
