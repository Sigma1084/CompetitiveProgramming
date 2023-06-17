#include "graphs.hpp"

/**
 * Calculates the shortest path from a source vertex to all
 *  the other vertices in a graph. <br>
 * Time complexity: O(n log n + m)
 * Space complexity: O(n + m)
 * where n is the number of vertices in the graph and m is the number of edges.
 * @param graph The graph represented as an adjacency list.
 * @param source The source vertex.
 * @return The shortest path from the source vertex to all the other vertices.
 */
std::vector<ll> dijkstra(
		const std::vector<std::vector<std::array<int, 2>>> &graph,
		int source) {
	int n = graph.size();
	assert(0 <= source < n);

	/**
	 * Initially, set the distance from the source vertex to all
	 *  other vertices to INF except for the source vertex in
	 *  which case the distance is set to 0.
	 */
	std::vector<ll> dist(n, INF);
	dist[source] = 0;

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
