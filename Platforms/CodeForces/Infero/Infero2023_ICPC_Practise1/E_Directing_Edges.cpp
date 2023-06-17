#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, m; cin >> n >> m;
	vector<array<int, 2>> edges;
	vector<vector<int>> adj(n);

	for (int _ = 0, t, u, v; _ < m; _++) {
		cin >> t >> u >> v; u--; v--;
		edges.push_back({u, v});
		if (t == 1) {
			adj[u].push_back(v);
		}
	}

	enum State { UNVISTED, VISITING, VISITED };
	vector<State> vis(n, UNVISTED);
	bool ok = true;

	vector<int> topo;

	function<void(int)> dfs = [&](int u) {
		vis[u] = VISITING;
		for (const int &v: adj[u]) {
			if (not ok) return;
			if (vis[v] == VISITING) {
				// We are in a cycle
				ok = false;
				return;
			}
			if (vis[v] == UNVISTED) {
				// We have more work to do
				dfs(v);
			}
		}
		vis[u] = VISITED;
		// We are done with u
		topo.push_back(u);
	};

	for (int i = 0; i < n; i++) {
		if (vis[i] == UNVISTED) {
			dfs(i);
		}
	}

	if (not ok) {
		cout << "NO\n";
		return;
	}

	reverse(all(topo));
	vector<int> pos(n);
	for (int i = 0; i < n; i++) {
		pos[topo[i]] = i;
	}

	cout << "YES\n";
	for (auto &[u, v]: edges) {
		if (pos[u] > pos[v]) {
			swap(u, v);
		}
		cout << u + 1 << ' ' << v + 1 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve();  // cout << '\n';
	}
	return 0;
}
