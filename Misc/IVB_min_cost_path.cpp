#include <bits/stdc++.h>
using namespace std;

struct Solution {
	int solve(int n, int m, vector<string> &grid);
};


int Solution::solve(int n, int m, vector<string> &grid) {
	auto isNotValid = [&] (int x, int y) {
		return x < 0 or y < 0 or x >= n or y >= m;
	};
	vector<vector<int>> dist(n, vector<int>(m, -1));

	vector<char> dirs = {'R', 'L', 'U', 'D'};
	map<char, int> dx = {{'R', 0}, {'L', 0}, {'U', -1}, {'D', 1}};
	map<char, int> dy = {{'R', 1}, {'L', -1}, {'U', 0}, {'D', 0}};

	deque<array<int, 3>> q;  // [x, y, d]
	q.push_back({0, 0, 0});
	while (not q.empty() and dist.back().back() == -1) {
		auto [x, y, d] = q.front(); q.pop_front();

		if (isNotValid(x, y)) continue;
		if (dist[x][y] != -1) continue;
		dist[x][y] = d;
		for (char c: dirs) {
			if (c == grid[x][y]) {
				q.push_front({ x + dx[c], y + dy[c], d });
			} else {
				q.push_back({ x + dx[c], y + dy[c], d + 1 });
			}
		}
	}

	return dist.back().back();
}

int main() {
	Solution s;
	int n, m; cin >> n >> m;
	vector<string> grid(n);
	for (string &row: grid) cin >> row;
	cout << s.solve(n, m, grid) << endl;
	return 0;
}
