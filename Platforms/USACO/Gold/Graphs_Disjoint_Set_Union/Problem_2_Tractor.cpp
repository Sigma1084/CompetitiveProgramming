#include <bits/stdc++.h>
using namespace std;

class DSU {
	const int n; // Number of nodes
	int nC; // Number of components
	vector<int> p;  // Parent
	vector<int> sz;  // Size of the component
public:
	DSU(int n): n(n), nC(n) { p.resize(n, -1); sz.resize(n, 1); }
	bool isLeader(int u) const { return p[u] < 0; }
	int size(int u) { return sz[find(u)]; }
	int numComp() const { return nC; }

	int find(int u) { 
		if (isLeader(u)) return u;
		return p[u] = find(p[u]);
	}

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return false;
		if (sz[u] < sz[v]) swap(u, v);
		p[v] = u; nC--;
		sz[u] += sz[v]; sz[v] = 0;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	freopen("tractor.in", "r", stdin);
	freopen("tractor.out", "w", stdout);

	int n; cin >> n;
	vector<vector<int>> h(n, vector<int>(n));
	for (auto &row: h)
		for (auto &node: row)
			cin >> node;

	priority_queue<array<int, 5>> edges;  // [-diff, x1, y1, x2, y2]
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + 1 < n) edges.push({-abs(h[i][j] - h[i+1][j]), i, j, i + 1, j});
			if (j + 1 < n) edges.push({-abs(h[i][j] - h[i][j+1]), i, j, i, j + 1});
		}
	}

	DSU dsu(n * n);  // [row*n + col]
	int ans = 0, maxCon = 1;

	while (maxCon < (n * n + 1) / 2) {
		auto [d, x1, y1, x2, y2] = edges.top(); edges.pop();
		dsu.merge(x1 * n + y1, x2 * n + y2);
		ans = -d; maxCon = max(maxCon, dsu.size(x1 * n + y1));
	}

	cout << ans;

	return 0;
}
