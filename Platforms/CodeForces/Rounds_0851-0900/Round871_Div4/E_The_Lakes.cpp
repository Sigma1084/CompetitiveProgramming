#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


template<typename T>
class Grid: public std::vector<std::vector<T>> {
	const int n, m;
	using Base = std::vector<std::vector<T>>;
	using DiffType = std::pair<short int, short int>;

public:
	using Node = std::pair<int, int>;

	constexpr static std::array<DiffType, 4> edgeIteratorDiff = {
		{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	};

	constexpr static std::array<DiffType, 8> fullIteratorDiff = {
		{{1, 0}, {-1, 0}, {0, 1}, {0, -1},
		 {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
	};

	Grid(int n, int m, bool makeVector = true): n(n), m(m) {
		if (makeVector) this->resize(n, std::vector<T>(m));
	}

	bool isValid(int x, int y) const {
		return 0 <= x and x < n and 0 <= y and y < m;
	}

	std::vector<Node> edgeIterator(int x, int y) const {
		std::vector<Node> edges;
		for (auto [dx, dy]: edgeIteratorDiff) {
			if (isValid(x + dx, y + dy)) {
				edges.emplace_back(x + dx, y + dy);
			}
		}
		return edges;
	}

	std::vector<Node> fullIterator(int x, int y) const {
		std::vector<Node> edges;
		for (auto [dx, dy]: fullIteratorDiff) {
			if (isValid(x + dx, y + dy)) {
				edges.emplace_back(x + dx, y + dy);
			}
		}
		return edges;
	}

	friend std::istream &operator >> (std::istream &in, Grid &grid) {
		for (auto &row: grid) {
			for (auto &cell: row) {
				in >> cell;
			}
		}
		return in;
	}
};


void solve() {
	int n, m; cin >> n >> m;
	Grid<int> grid(n, m);
	Grid<bool> vis(n, m);
	cin >> grid;

	int ans = 0, cur = 0;
	function <void(int, int)> dfs = [&] (int r, int c) {
		if (!grid[r][c] or vis[r][c]) return;
		vis[r][c] = true;
		cur += grid[r][c];
		for (auto [r1, c1]: grid.edgeIterator(r, c))
				dfs(r1, c1);
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
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