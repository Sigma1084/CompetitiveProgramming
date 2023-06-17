#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
constexpr ll INF = 1e18;


std::vector<ll> dijkstra(
		const std::vector<std::vector<std::array<int, 2>>> &graph,
		int source) {
	int n = graph.size();
	/**
	 * Initially, set the distance from the source vertex to all
	 *  other vertices to INF except for the source vertex in
	 *  which case the distance is set to 0.
	 */
	std::vector<ll> dist(n, INF);

	/**
	 * Use a min-heap to store the vertices in increasing order
	 *  of their distance from the source vertex.
	 */
	using Edge = std::pair<ll , int>;  // (distance, vertex)
	std::priority_queue<Edge, std::vector<Edge>, std::greater<>> pq;
	pq.push({0, source});

	while (not pq.empty()) {
		auto [d, u] = pq.top();  // (distance, vertex)
		pq.pop();
		if (dist[u] != INF) continue;
		dist[u] = d;
		for (auto [v, w] : graph[u]) {
			if (dist[v] == INF) {
				pq.push({d + w, v});
			}
		}
	}

	return dist;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<vector<array<int, 2>>> graph(n);
	vector<vector<array<int, 2>>> graphRev(n);
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w; u--; v--;
		graph[u].push_back({v, w});
		graphRev[v].push_back({u, w});
	}

	auto distStart = dijkstra(graph, 0);
	auto distEnd = dijkstra(graphRev, n - 1);

	ll ans = INF;
	for (int u = 0; u < n; ++u) {
		for (auto [v, w] : graph[u]) {
			ans = min(ans, distStart[u] + w / 2 + distEnd[v]);
		}
	}

	cout << ans << endl;
}
