#pragma once

#include<vector>

class DSU {
	const int n; // Number of nodes
	int nC; // Number of components
	std::vector<int> p;  // Parent
	std::vector<int> sz;  // Size of the component
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
		if (sz[u] < sz[v]) std::swap(u, v);
		p[v] = u; nC--;
		sz[u] += sz[v]; sz[v] = 0;
		return true;
	}
};
