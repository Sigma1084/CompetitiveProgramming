#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, m; cin >> n >> m;
	vector<string> grid(n);

	for (auto &x: grid) cin >> x;
	vector<vector<array<bool, 2>>> reachable(n, vector<array<bool, 2>>(m, {false, false}));

	auto valid = [&](int r, int c) {
		return r >= 0 and r < n and c >= 0 and c < m;
	};

	reachable[n-1][m-1][1] = true;
	for (int r = n-1; r >= 0; r--) {
		for (int c = m-1; c >= 0; c--) {
			if (grid[r][c] == '#') continue;
			if (valid(r+1, c) and reachable[r+1][c][1]) {
				reachable[r][c][1] = true;
			} else if (valid(r, c+1) and reachable[r][c+1][1]) {
				reachable[r][c][1] = true;
			}
		}
	}

	reachable[0][0][0] = true;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			if (grid[r][c] == '#') continue;
			if (valid(r-1, c) and reachable[r-1][c][0]) {
				reachable[r][c][0] = true;
			} else if (valid(r, c-1) and reachable[r][c-1][0]) {
				reachable[r][c][0] = true;
			}
		}
	}

	/**
	 * If there is no path from (0, 0) to (n-1, m-1), answer is 0
	 */
	if (reachable[0][0][0] == false or reachable[0][0][1] == false) {
		cout << 0;
		return;
	}

	/**
	 * If there is a diagonal with only 1 reachable cell, answer is 1
	 */

	vector<int> d(n + m - 1, 0);
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			if (reachable[r][c][0] and reachable[r][c][1]) d[r+c]++;
		}
	}

	for (int i = 1; i < n + m - 2; i++) {
		if (d[i] == 1) {
			cout << 1;
			return;
		}
	}

	/**
	 * Otherwise, answer is 2
	 */
	cout << 2;
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
