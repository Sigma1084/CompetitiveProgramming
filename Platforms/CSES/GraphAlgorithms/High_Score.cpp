#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
constexpr ll INF = 1e17;

std::vector<ll> bellmanFord(
		const std::vector<std::vector<std::array<int, 2>>> &graph,
		int source) {
	int n = graph.size();

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
	 * Now, propagate the edges one more time
	 * to check for negative cycles
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

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<vector<array<int, 2>>> e(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--; v--;
		// We negate the weight because we want to find the
		//  longest path instead of the shortest path.
		e[u].push_back({v, -w});
	}

	// We run Bellman-Ford from node 1.
	auto dist = bellmanFord(e, 0);

	if (dist[n - 1] == -INF) {
		cout << -1 << endl;
	} else {
		cout << -dist[n - 1] << endl;
	}

	return 0;
}