#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

constexpr array<int, 4> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<string> grid(n);
	for (string &s: grid) cin >> s;

	function<bool(int, int)> isValid = [&] (int x, int y) {
		return 0 <= x and x < n and 0 <= y and y < m and grid[x][y] != '.';
	};

	int ans = 0;
	vector<vector<int>> dist(n, vector<int>(m, -1));
	dist[0][0] = 1;

	deque<array<int, 2>> q;  // {x, y}
	q.push_back({0, 0});

	while (not q.empty()) {
		auto [x0, y0] = q.front(); q.pop_front();
		ans = max(ans, dist[x0][y0]);
		for (int i = 0; i < 4; i++) {
			int x = x0 + dx[i], y = y0 + dy[i];
			if (not isValid(x, y) or dist[x][y] != -1) continue;
			if (grid[x][y] != grid[x0][y0]) {
				dist[x][y] = dist[x0][y0] + 1;
				q.push_back({x, y});
			} else {
				dist[x][y] = dist[x0][y0];
				q.push_front({x, y});
			}
		}
	}

	cout << ans;

	return 0;
}
