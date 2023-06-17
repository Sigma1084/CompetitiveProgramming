#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

using DiffType = std::pair<short int, short int>;
constexpr static std::array<DiffType, 4> edgeIteratorDiff = {
	{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
};


void solve() {
	int n, m; cin >> n >> m;
	std::vector<std::vector<int>> grid(n, vector<int>(m));

	auto isValid = [m, n](int x, int y) {
		return 0 <= x and x < n and 0 <= y and y < m;
	};

	int ans = 0, cur = 0;
	function <void(int, int)> dfs = [&] (int r, int c) {
		if (!grid[r][c] or vis[r][c]) return;
		vis[r][c] = true;
		cur += grid[r][c];
		for (auto [r1, c1]: grid.edgeIterator(r, c))
			dfs(r1, c1);
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!grid[i][j] or vis[i][j]) continue;
			cur = 0;
			dfs(i, j);
			ans = max(ans, cur);
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
