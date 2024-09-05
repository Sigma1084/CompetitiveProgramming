#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n); for (auto &i: a) cin >> i;
	vector<vector<int>> adj(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> sz(n);  // Size of the subtree rooted at x
	vector<ll> imp(n);  // Importance of the subtree rooted at x
	vector<int> p(n, -1);  // Parent of the node
	vector<set<pair<int, int>>> info(n);  // info.first() is the one with the largest size
	// Pass as [-SIZE, INDEX]

	function<void(int)> dfs = [&](int u) {
		// Here, par is the parent
		imp[u] = a[u];
		sz[u] = 1;
		for (auto v: adj[u]) {
			if (v == p[u]) continue;
			p[v] = u;
			dfs(v);
			imp[u] += imp[v];  // Add the importance
			sz[u] += sz[v];  // The subtree size is increased
		}
		if (u) info[p[u]].insert({-sz[u], u});
	};
	dfs(0);

	function<void()> debug = [&] () {
		cerr << "Node : "; for (int u = 0; u < n; u++) cerr << u+1 << ' '; cerr << '\n';
		cerr << "Par  : "; for (int u = 0; u < n; u++) cerr << p[u]+1 << ' '; cerr << '\n';
		cerr << "Size : "; for (int u = 0; u < n; u++) cerr << sz[u] << ' '; cerr << '\n';
		cerr << "Imp  : "; for (int u = 0; u < n; u++) cerr << imp[u] << ' '; cerr << '\n';
		for (int u = 0; u < n; u++) {
			cerr << u << ": ";
			for (auto [x, y]: info[u]) cerr << x << ' ' << y << "  ";
			cerr << '\n';
		}
		cerr << '\n';
	};

	for (int i = 0, t, x; i < m; i++) {
		cin >> t >> x; x--;
		if (t == 1) {
			cout << imp[x] << '\n';
			continue;
		}

		assert(t == 2);
		assert(x != 0);
		if (info[x].empty()) continue;

		auto [_, c] = *info[x].begin();  // Extract the size and child
		info[x].erase(info[x].begin());  // Remove the child from x
		info[p[x]].erase({-sz[x], x});  // Remove x from it's parent

		// Update

		sz[x] -= sz[c];  // The size is gone
		imp[x] -= imp[c];  // The importance of child is gone

		sz[c] += sz[x];  // Size comes to child
		imp[c] += imp[x];  // Importance comes to child

		info[p[x]].insert({-sz[c], c});  // Insert c to x's parent
		p[c] = p[x];
		p[x] = c;

		// Reinsert

		info[p[x]].insert({-sz[x], x});  // Insert x to c
		info[p[c]].insert({-sz[c], c});  // Insert c to x's parent

		// debug();
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}

	return 0;
}
