#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for (auto &v: grid) {
		for (int &i: v) {
			cin >> i;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 0) continue;
			for (int ii = i - 1; ii >= 0 and grid[ii][j] == 0; ii--) ans++;
			for (int ii = i + 1; ii < n and grid[ii][j] == 0; ii++) ans++;
			for (int jj = j - 1; jj >= 0 and grid[i][jj] == 0; jj--) ans++;
			for (int jj = j + 1; jj < m and grid[i][jj] == 0; jj++) ans++;
		}
	}

	cout << ans;
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
