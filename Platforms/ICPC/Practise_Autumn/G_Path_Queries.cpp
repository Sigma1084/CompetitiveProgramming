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

	int n, q; cin >> n >> q;
	using Edge = array<int, 3>;
	vector<Edge> e(n - 1);

	for (auto &[w, u, v]: e) {
		cin >> u >> v >> w;
		u--; v--;
	}

	sort(e.begin(), e.end());

	vector<array<int, 2>> queries(q);
	for (int i = 0, x; i < q; i++) {
		cin >> x;
		queries[i] = { x, i };
	}
	sort(queries.begin(), queries.end());

	DSU dsu(n);

	ll cur = 0;
	vector<ll> ans(q);
	for (int i = 0, j = 0; j < q; j++) {
		for (; i + 1 < n and e[i][0] <= queries[j][0]; i++) {
			// Merge u, v
			auto [w, u, v] = e[i];
			if (dsu.find(u) == dsu.find(v)) continue;
			int sU = dsu.size(u);
			int sV = dsu.size(v);
			cur -= (1LL * sU * (sU + 1) / 2);
			cur -= (1LL * sV * (sV + 1) / 2);
			dsu.merge(u, v);
			sU = dsu.size(u);
			cur += (1LL * sU * (sU + 1) / 2);
		}
		ans[queries[j][1]] = cur;
	}

	for (ll x: ans) {
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}
