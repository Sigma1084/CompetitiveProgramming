#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

/**
 * bes[i] := Min energy required for Bessie to reach node i
 * els[i] := Min energy required for Elsie to reach node i
 * end[i] := Min energy from node i to finish together
 */
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	freopen("piggyback.in", "r", stdin);
	freopen("piggyback.out", "w", stdout);

	int b, e, p, n, m;
	cin >> b >> e >> p >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// Perform 3 bfs's to compute the distances
	auto bfs = [n, &adj](int start, int cost) {
		vector<ll> dist(n, -1);
		queue<pair<ll, int>> q;
		q.push({0, start});
		while (not q.empty()) {
			auto [d, u] = q.front(); q.pop();
			if (dist[u] != -1) continue;
			dist[u] = d;
			for (auto v: adj[u]) {
				q.push({d + cost, v});
			}
		}
		return dist;
	};

	vector<ll> bes = bfs(0, b);
	vector<ll> els = bfs(1, e);
	vector<ll> end = bfs(n-1, p);

	ll ans = bes[n-1] + els[n-1];
	for (int i = 0; i < n; i++) {
		ans = min(ans, bes[i] + els[i] + end[i]);
	}
	cout << ans;

	return 0;
}
