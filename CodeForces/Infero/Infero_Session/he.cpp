#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + 1);

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> q;
	vector<bool> vis(n+1, false);
	vector<int> d(n+1);

	d[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = true;
		for (auto &v: adj[u]) {
			if (!vis[v]) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}

	cout << d[n] << '\n';
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}