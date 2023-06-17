#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
	vector<int64_t> dist(n, -1);

	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w; u--; v--;
		adj[u].push_back({v, w});
	}

	using Edge = pair<int64_t , int>;  // (Distance, u)
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	pq.push({0, 0});

	while (not pq.empty()) {
		auto [d, u] = pq.top();  // (distance, vertex)
		pq.pop();
		if (dist[u] != -1) continue;
		dist[u] = d;
		for (auto [v, w] : adj[u]) {
			if (dist[v] == -1) {
				pq.push({d + w, v});
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << dist[i] << ' ';
	}

	return 0;
}
