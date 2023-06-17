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

	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);

	int n, m; cin >> n >> m;

	vector<int> pos(n);  // position of cow i
	for (int &p: pos) { cin >> p; p--; }

	vector<array<int, 3>> edges(m);  // [weight, u, v]
	for (auto &[w, u, v]: edges) {
		cin >> u >> v >> w;
		u--; v--;
	}

	sort(edges.begin(), edges.end(), greater<>());
	DSU dsu(n);
	int ans = INT_MAX, c = 0;  // Number of nodes checked

	for (auto [w, u, v]: edges) {
		while (c < n and dsu.find(c) == dsu.find(pos[c])) c++;
		if (c == n) break;
		dsu.merge(u, v);
		ans = w;
	}

	if (ans == INT_MAX) ans = -1;
	cout << ans << endl;

	return 0;
}
