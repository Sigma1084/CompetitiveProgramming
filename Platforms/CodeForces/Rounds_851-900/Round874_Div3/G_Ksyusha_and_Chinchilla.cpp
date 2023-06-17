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

void solve() {
	int n; cin >> n;
	vector<set<int>> adj(n);
	vector<array<int, 2>> edges(n - 1);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v; u--; v--;
		adj[u].insert(v);
		adj[v].insert(u);
		edges[i] = {u, v};
	}

	if (n % 3) {
		cout << -1;
		return;
	}

	DSU dsu(n);
	vector<bool> mid(n);
	set<pair<int, int>> verts;  // [degree, vertex]

	for (int i = 0; i < n; i++) {
		verts.insert({adj[i].size(), i});
	}

	auto isolate = [&] (int v) {
		for (auto w: adj[v]) {
			verts.erase({adj[w].size(), w});
			adj[w].erase(v);
			verts.insert({adj[w].size(), w});
		}
		verts.erase({adj[v].size(), v});
		adj[v].clear();
	};

	while (not verts.empty()) {
		auto [deg, u] = *verts.begin();
		verts.erase(verts.begin());
		if (deg != 1) {
			// Based on the fact that we can always find a leaf node
			cout << -1;
			return;
		}
		int v = *adj[u].begin();
		dsu.merge(u, v);
		isolate(u);

		if (mid[u] and mid[v]) {
			cout << -1;
			return;
		} else if (mid[u] or mid[v]) {
			isolate(v);
		} else {
			mid[v] = true;
		}
	}

	vector<int> remEdges;
	for (int i = 0; i < n - 1; i++) {
		auto [u, v] = edges[i];
		if (dsu.find(u) != dsu.find(v)) {
			remEdges.push_back(i + 1);
		}
	}

	cout << remEdges.size() << '\n';
	for (int e: remEdges) cout << e << ' ';
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
