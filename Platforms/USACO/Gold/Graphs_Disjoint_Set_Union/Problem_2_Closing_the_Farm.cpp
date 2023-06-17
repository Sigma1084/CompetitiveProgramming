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

	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);

	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> order(n);
	for (int &i: order) { cin >> i; i--; }
	reverse(order.begin(), order.end());

	// We can think of it as adding vertices in the opposite order
	vector<int> pos(n);
	for (int i = 0; i < n; i++) {
		pos[order[i]] = i;
	}

	vector<string> ans;
	DSU dsu(n);
	for (int u: order) {
		for (int v: adj[u]) {
			if (pos[v] < pos[u]) {
				dsu.merge(u, v);
			}
		}
		if (dsu.numComp() == n - pos[u]) {
			ans.push_back("YES");
		} else {
			ans.push_back("NO");
		}
	}
	reverse(ans.begin(), ans.end());

	for (const string &s: ans) {
		cout << s << '\n';
	}

	return 0;
}
