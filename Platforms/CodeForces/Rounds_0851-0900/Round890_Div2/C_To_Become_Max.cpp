#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

/**
 * dp[i][0] := Minimum k for a[i] to become maxVal - 0
 * dp[i][1] := Minimum k for a[i] to become maxVal - 1
 * dp[i][2] := Minimum k for a[i] to become maxVal - 2
 */
void solve() {
	int n, K; cin >> n >> K;
	vector<int> a(n); for (auto &x: a) cin >> x;

	vector<int> maxVal = a;
	for (int i = 0; i < n; i++) {
		for (int j = 1; i + j < n; j++) {
			maxVal[i] = max(maxVal[i], a[i + j] + j);
		}
	}

	int lim = 0;
	while (lim < n and maxVal[lim] != a[lim]) lim++;
	n = lim + 1;

	vector<vector<ll>> dp(n, vector<ll>(n));

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (a[i] >= maxVal[i] - j) dp[i][j] = 0;
			else dp[i][j] = dp[i + 1][j] + maxVal[i] - j - a[i];
		}
	}

	int ans = a[n - 1];
	for (int k = 1; k < n; k++, ans++) {
		ll mn = K + 1;
		for (int i = 0; i + k < n; i++) {
			mn = min(mn, dp[i][n - k - i - 1]);
		}
		if (mn > K) break;
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
