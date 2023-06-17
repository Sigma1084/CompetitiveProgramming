#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;
	map<int, int> dp;

	for (auto i = n - 1; i >= 0; i--) {
		auto x = a[i];
		dp[x] = 0;
		for (int y = 2 * x; y <= dp.rbegin()->first; ) {
			if (dp.find(y) != dp.end())
				dp[x] = max(dp[x], dp[y]);
			if (dp.upper_bound(y + x) == dp.end())
				break;
			y = dp.upper_bound(y + x)->first;
			if (y % x)
				y = y / x * x + x;
		}
		dp[x] += 1;
	}

	int ans = 0;
	for (auto [x, c]: dp)
		ans = max(ans, c);
	
	cout << ans;
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
