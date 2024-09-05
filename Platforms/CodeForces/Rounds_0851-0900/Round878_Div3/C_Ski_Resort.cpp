#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, k, q; cin >> n >> k >> q;
	vector<int> a(n); for (auto &x: a) cin >> x;
	ll ans = 0;

	if (k > n) { cout << 0; return; }

	vector<ll> dp(n + 1);
	dp[k] = 1;
	for (int i = k + 1; i <= n; i++) {
		dp[i] = dp[i - 1] + i - k + 1;
	}

	a.push_back(q + 1);  // For termination
	int len = 0;
	for (int x: a) {
		if (x <= q) {
			len++;
		} else {
			ans += dp[len];
			len = 0;
		}
	}

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
