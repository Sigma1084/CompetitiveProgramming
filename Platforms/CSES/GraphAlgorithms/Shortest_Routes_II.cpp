#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


std::vector<std::vector<ll>> floyd_warshall(
		const std::vector<std::vector<std::array<int, 2>>> &graph) {
	constexpr ll INF = 1e18;
	int n = graph.size();
	std::vector<std::vector<ll>> dist(n, std::vector<ll>(n, INF));

	/**
	 * Initially, set the distance between all pairs of vertices to INF
	 * except for the vertices that are connected by an edge
	 * in which case the distance is set to the weight of the edge.
	 */
	for (int u = 0; u < n; ++u) {
		for (auto [v, w] : graph[u]) {
			dist[u][v] = std::min(dist[u][v], ll(w));
		}
	}

	/**
	 * dist[u][u] = 0 for all u
	 */
	for (int u = 0; u < n; ++u) {
		dist[u][u] = 0;
	}

	/**
	 * For each vertex k, update the distance between all pairs of vertices
	 * by considering the distance between u and v
	 * (and the distance between u and k) + (the distance between k and v)
	 */
	for (int k = 0; k < n; ++k) {
		for (int u = 0; u < n; ++u) {
			for (int v = 0; v < n; ++v) {
				dist[u][v] = std::min(dist[u][v], dist[u][k] + dist[k][v]);
			}
		}
	}

	return dist;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >> n >> m >> q;
	vector<vector<array<int, 2>>> graph(n);
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w; u--; v--;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

	auto dist = floyd_warshall(graph);
	for (int i = 0, u, v; i < q; ++i) {
		cin >> u >> v; u--; v--;
		cout << (dist[u][v] > 1e17 ? -1 : dist[u][v]) << '\n';
	}

	return 0;
}

