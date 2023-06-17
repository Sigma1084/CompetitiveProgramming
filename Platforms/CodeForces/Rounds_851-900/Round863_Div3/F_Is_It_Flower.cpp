#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


struct DSU {
	vector<int> p, sz;

	DSU() = default;
	DSU(int n) { init(n); }

	void init(int n) {
		p.resize(n);
		iota(p.begin(), p.end(), 0);
		sz.assign(n, 1);
	}

	int leader(int u) {
		if (p[u] == u) return u;
		return p[u] = leader(p[u]);
	}

	bool merge(int u, int v) {
		u = leader(u); v = leader(v);
		if (u == v) return false;
		sz[u] += sz[v]; sz[v] = 0;
		p[v] = u;
		return true;
	}

	int size(int x) {
		return sz[leader(x)];
	}
};

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	/**
	 * Now, in a k-flower, we need to have k vertices in the main cycle
	 * Each vertex has its own k-cycle => (Has extra k-1 vertices of degree 2 with it)
	 * 
	 * Hence, the total number of vertices in a k-flower is k + k(k-1) = k^2
	 * 
	 * The Main Cycle Vertices have a degree of 4 while the rest of the vertices have 2
	 * We check if a cycle happens in the main blocks first
	 * 
	 * So, the number of edges will be k^2 + k
	 */

	int k = sqrt(n);

	if (k * k != n or k * (k + 1) != m) {
		cout << "NO";
		return;
	}

	int fourCycleRep = -1;
	DSU d4(n), d2(n);  // Must have k components in the end
	vector<int> e2(n);  // Number of side cycle edges from i
	int m4 = 0;  // Number of main cycle edges

	for (int u = 0; u < n; ++u) {
		if (adj[u].size() != 4 and adj[u].size() != 2) {
			cout << "NO";
			return;
		}
		for (int v: adj[u]) {
			if (v > u) {
				// We want to do it only once
				continue;
			} else if (adj[u].size() == 4 and adj[v].size() == 4) {
				m4 += 1;
				d4.merge(u, v);
				fourCycleRep = u;
			} else {
				e2[u] += 1;
				e2[v] += 1;
				d2.merge(u, v);
			}
		}
	}

	if (fourCycleRep == -1 or d4.size(fourCycleRep) != k or m4 != k) {
		cout << "NO";
		return;
	}

	for (int u = 0; u < n; ++u) {
		if (e2[u] != 2 or d2.size(u) != k) {
			cout << "NO";
			return;
		}
	}

	/**
	 * We have established a few facts
	 * - The number of vertices and edges is k^2 and k(k+1) resp.
	 * - The main cycle has exactly k vertices and edges
	 * - Every vertex has exactly 2 edges to the side cycles
	 * - The side cycles have exactly k vertices in them
	 */

	set<int> l2;
	for (int u = 0; u < n; ++u) {
		if (adj[u].size() == 4) {
			l2.insert(d2.leader(u));
		}
	}

	if (l2.size() != k) {
		cout << "NO";
		return;
	}

	cout << "YES";
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
