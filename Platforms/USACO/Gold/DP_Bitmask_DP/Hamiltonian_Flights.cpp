#include <bits/stdc++.h>
using namespace std;

constexpr int P = 1'000'000'007;

/**
 * dp[mask][v] : Number of ways of reaching from node 0 to node v
 * such that all the nodes in the mask are traversed once
 */

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<vector<int>> adjMat(n, vector<int>(n));
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--; v--;
		adjMat[u][v] += 1;
	}

	// dp[mask][v]
	vector<vector<int>> dp(1 << n, vector<int>(n));
	dp[1][0] = 1;  // dp[Covering 0][ending at 0] = 1

	for (int mask = 3; mask < (1 << n); mask += 2) {
		for (int v = 0; v < n; v++) {
			if (!(1 << v & mask)) continue;

			// Calculate dp[mask][v]
			for (int u = 0; u < n; u++) {
				if ((mask & (1 << u)) and adjMat[u][v] and u != v) {
					dp[mask][v] = (dp[mask][v] + 
						1LL * dp[mask - (1 << v)][u] * adjMat[u][v]) % P;
				}
			}
		}
	}

	cout << dp[(1 << n) - 1][n - 1];

	return 0;
}
