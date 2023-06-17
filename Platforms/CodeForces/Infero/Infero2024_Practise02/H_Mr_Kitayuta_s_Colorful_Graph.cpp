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

	int n, m, q; cin >> n >> m;
	vector<DSU> dsus(m, DSU(n));

	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		a--; b--; c--;
		dsus[c].merge(a, b);
	}

	cin >> q;
	for (int i = 0, a, b, ans; i < q; i++) {
		cin >> a >> b;
		a--; b--;
		ans = 0;
		for (auto &dsu: dsus)
			ans += dsu.find(a) == dsu.find(b);
		cout << ans << '\n';
	}

	return 0;
}
