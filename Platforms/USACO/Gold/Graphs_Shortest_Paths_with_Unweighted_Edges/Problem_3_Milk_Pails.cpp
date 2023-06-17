#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);

	int X, Y, k, m;
	cin >> X >> Y >> k >> m;

	// Stores the minimum turn in which this happened
	vector<vector<int>> dp(X + 1, vector<int>(Y + 1, -1));

	queue<pair<int, int>> q; q.push({0, 0});
	for (int t = 0, x2, y2; t <= k; t++) {
		for (int i = 0, n = q.size(); i < n; i++) {
			auto [x, y] = q.front(); q.pop();
			if (dp[x][y] != -1) continue;
			dp[x][y] = t;  // Happens in this turn
			q.push({X, y});  // Fill the first one
			q.push({x, Y});  // Fill the second one
			q.push({0, y});  // Empty the first one
			q.push({x, 0});  // Empty the second one
			y2 = min(Y, x + y);  // Pour first to second
			q.push({x + y - y2, y2});
			x2 = min(X, y + x);  // Pour second to first
			q.push({x2, x + y - x2});
		}
	}

	int ans = m;
	for (int x = 0; x <= X; x++) {
		for (int y = 0; y <= Y; y++) {
			if (dp[x][y] != -1)
			ans = min(ans, abs(x + y - m));
		}
	}

	cout << ans;

	return 0;
}
