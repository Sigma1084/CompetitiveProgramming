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


void solve() {
	int n; cin >> n;
	
	set<array<int, 2>> edges;
	DSU dsu(n);

	for (int u = 0, v; u < n; u++) {
		cin >> v; v--;
		edges.insert({min(u, v), max(u, v)});
		dsu.merge(u, v);
	}

	vector<int> degree(n);
	for (auto [u, v]: edges) {
		degree[u]++;
		degree[v]++;
	}

	map<int, pair<int, int>> deg;
	for (int i = 0; i < n; i++) {
		if (degree[i] == 1) {
			deg[dsu.find(i)].first++;
		} else if (degree[i] == 2) {
			deg[dsu.find(i)].second++;
		} else {
			// assert(false);
			cerr << "WHAT";
		}
	}

	array<int, 2> ans;
	ans[0] = 1;
	ans[1] = deg.size();

	for (auto [d1, d2]: deg) {
		if (d2.first == 0)
			ans[0]++;
	}

	cout << min(ans[1], ans[0]) << ' ' << ans[1];
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
