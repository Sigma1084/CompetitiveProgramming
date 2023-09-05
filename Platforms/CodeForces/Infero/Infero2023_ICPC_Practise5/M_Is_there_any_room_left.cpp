#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<vector<bitset<4>>> g(n, vector<bitset<4>>(m));
	for (auto &r: g) {
		for (auto &x: r) {
			int _x; cin >> _x;
			x = _x;
		}
	}

	constexpr array<int, 4> dr = {-1, 0, 1, 0};
	constexpr array<int, 4> dc = {0, 1, 0, -1};

	vector<vector<bool>> vis(n, vector<bool>(m));

	function<bool(int, int)> isValid = [&] (int r, int c) {
		return 0 <= r and r < n and 0 <= c and c < m;
	};

	int cur = 0;
	function<void(int, int)> dfs = [&] (int r, int c) {
		if (vis[r][c]) return;
		cur++;
		vis[r][c] = true;
		for (int i = 0; i < 4; i++) {
			if (!g[r][c][3-i] and isValid(r + dr[i], c + dc[i])) {
				dfs(r + dr[i], c + dc[i]);
			}
		}
	};

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j]) {
				cur = 0;
				dfs(i, j);
				ans.push_back(cur);
			}
		}
	}

	sort(ans.begin(), ans.end(), greater<>());
	for (int x: ans) cout << x << ' ';
	cout << endl;
	return 0;
}
