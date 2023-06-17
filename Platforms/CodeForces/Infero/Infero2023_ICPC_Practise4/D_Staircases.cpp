#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, m, q; cin >> n >> m >> q;

	/**
	 * dp[r][c][0] : Number of paths when u go right from (r, c)
	 * dp[r][c][1] : Number of paths when u go down from (r, c)
	 */
	vector<vector<array<ll, 2>>> dp(n, vector<array<ll, 2>>(m, {0, 0}));
	vector<vector<bool>> locked(n, vector<bool>(m, false));
	ll ans = n * m;

	auto updateDP = [&] (int r, int c) {
		ans -= dp[r][c][0] + dp[r][c][1];
		if (locked[r][c]) {
			dp[r][c][0] = dp[r][c][1] = 0;
			return;
		}
		if (c + 1 < m) {
			dp[r][c][0] = dp[r][c+1][1] + 1 - locked[r][c+1];
		}
		if (r + 1 < n) {
			dp[r][c][1] = dp[r+1][c][0] + 1 - locked[r+1][c];
		}
		ans += dp[r][c][0] + dp[r][c][1];
	};

	for (int r = n-1; r >= 0; r--) {
		for (int c = m-1; c >= 0; c--) {
			updateDP(r, c);
		}
	}

	for (int _ = 0, x, y; _ < q; _++) {
		cin >> x >> y; x--; y--;

		if (locked[x][y]) {
			// Here, we are unlocking it
			locked[x][y] = false;
			ans += 1;
		} else {
			// Here, we are locking it
			locked[x][y] = true;
			ans -= 1;
		}

		updateDP(x, y);
		for (int r = x-1, c = y-1; r >= -1 and c >= -1; r--, c--) {
			if (r + 1 < n and c >= 0) updateDP(r+1, c);
			if (r >= 0 and c + 1 < m) updateDP(r, c+1);
			if (r >= 0 and c >= 0) updateDP(r, c);
		}

		cout << ans << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
