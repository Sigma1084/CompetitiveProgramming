#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<string> b(n);
	for (string &s: b) cin >> s;

	/**
	 * maxWidth[r][c][h] := MaxWidth of the array toplefted at (r, c)
	 * with height h
	 */
	vector<vector<vector<int>>> maxWidth(n,
		vector<vector<int>>(n, vector<int>(n)));

	for (int r = n-1; r >= 0; r--) {
		for (int c = n-1; c >= 0; c--) {
			for (int h = 0; h + r < n; h++) {
				if (h and b[r + h][c] == b[r + h - 1][c]) break;
				if (c != n-1 and b[r + h][c] == b[r + h][c + 1]) {
					maxWidth[r][c][h] = 1 + maxWidth[r][c + 1][h];
				} else {
					maxWidth[r][c][h] = 1;
				}
			}
		}
	}

	int ans = 0;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			for (int h = 0; h < n; h++) {
				if (maxWidth[r][c][h] == 0) break;
				// Column after CANNOT consume it by definition
				if (r and maxWidth[r - 1][c][h + 1] == maxWidth[r][c][h]) {
					// Row before consumes it
				} else if (c and maxWidth[r][c - 1][h] == maxWidth[r][c][h] + 1) {
					// Column before consumes it
				} else if (r + h + 1 < n and maxWidth[r][c][h + 1] == maxWidth[r][c][h]) {
					// Row after consumes it
				} else {
					ans++;
				}
			}
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
