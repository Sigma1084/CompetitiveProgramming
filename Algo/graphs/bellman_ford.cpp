#include "graphs.hpp"

/**
 * Calculates the shortest path from a source vertex to all
 *  the other vertices in a graph. <br>
 * This algorithm can also be used to detect negative cycles in the graph.
 * If a negative cycle is detected, the distance of all the vertices
 *  in the cycle is set to -INF. <br>
 * Time complexity: O(n * m)
 * Space complexity: O(n + m)
 * where n is the number of vertices in the graph and m is the number of edges.
 * @param graph The graph represented as an adjacency list.
 * @param source The source vertex.
 * @return The shortest path from the source vertex to all the other vertices.
 */
std::vector<ll> bellmanFord(
		const std::vector<std::vector<std::array<int, 2>>> &graph,
		int source) {
	int n = graph.size();
	assert(0 <= source < n);

	/**
	 * Initially, we set the distance of all nodes to infinity
	 */
	std::vector<ll> dist(n, INF);

	/**
	 * Propagate the edges n - 1 times
	 */
	dist[source] = 0;
	for (int i = 1; i <= n - 1; ++i) {
		for (int u = 0; u < n; ++u) {
			for (auto [v, w]: graph[u]) {
				if (dist[u] == INF) continue;  // u is unreachable
				dist[v] = std::min(dist[v], dist[u] + w);
			}
		}
	}

	/**
	 * Now, propagate the edges one more time to check for negative cycles
	 */
	std::queue<int> q;
	for (int u = 0; u < n; ++u) {
		for (auto [v, w]: graph[u]) {
			if (dist[u] == INF) continue;  // u is unreachable
			if (dist[v] > dist[u] + w) {
				q.push(v);
			}
		}
	}

	while (not q.empty()) {
		auto u = q.front(); q.pop();
		dist[u] = -INF;
		for (auto [v, w]: graph[u]) {
			if (dist[v] == -INF) continue;
			q.push(v);
		}
	}

	return dist;
}
