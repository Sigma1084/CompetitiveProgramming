#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

class DSU {
	int n;
	vector<int> p;
	vector<int> sz;
public:
	DSU(int n): n(n) { p.resize(n, -1); sz.resize(n, 1); }
	bool isLeader(int u) { return p[u] < 0; }
	int size(int u) { return sz[find(u)]; }

	int find(int u) { 
		if (isLeader(u)) return u;
		return p[u] = find(p[u]);
	}

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return false;
		if (sz[u] < sz[v]) swap(u, v);
		p[v] = u; sz[u] += sz[v]; sz[v] = 0;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m; cin >> n >> m;
	DSU dsu(n);

	int numConnected = n, largest = 1;
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--; v--;
		numConnected -= dsu.find(u) != dsu.find(v);
		dsu.merge(u, v);
		largest = max({ largest, dsu.size(u), dsu.size(v) });
		cout << numConnected << ' ' << largest << '\n';
	}

	return 0;
}
