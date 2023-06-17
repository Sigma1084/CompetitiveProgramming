#include "graphs.hpp"

/**
 * Calculates the shortest path between all pairs of vertices in a graph <br>
 * Time complexity: O(n^3)
 * Space complexity: O(n^2)
 * where n is the number of vertices in the graph.
 * @param graph The graph represented as an adjacency matrix.
 * @return The shortest path between all pairs of vertices in the graph.
 */
std::vector<std::vector<ll>> floydWarshall(
		const std::vector<std::vector<std::array<int, 2>>> &graph) {
	int n = graph.size();

	/**
	 * Initially, set the distance between all pairs of vertices to INF
	 * except for the vertices that are connected by an edge
	 * in which case the distance is set to the weight of the edge.
	 */
	std::vector<std::vector<ll>> dist(n, std::vector<ll>(n, INF));
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
