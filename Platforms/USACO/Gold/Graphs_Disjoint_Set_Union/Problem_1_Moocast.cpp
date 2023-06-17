#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

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

	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

	int n; cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	priority_queue<array<int, 3>> edges;
	for (int i = 0, d; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			d = (x[i] - x[j]) * (x[i] - x[j])
				+ (y[i] - y[j]) * (y[i] - y[j]);
			edges.push({-d, i, j});
		}
	}

	DSU dsu(n);
	int ans = 0;
	while (dsu.numComp() > 1) {
		auto [w, i, j] = edges.top(); edges.pop();
		dsu.merge(i, j);
		ans = -w;
	}

	cout << ans << endl;

	return 0;
}
