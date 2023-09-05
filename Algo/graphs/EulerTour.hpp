#include <vector>
#include <functional>

class EulerTour {
	const int n;
	int root;
	std::vector<int> p;  // parent
	std::vector<int> tour;  // euler tour
	std::vector<int> in;  // in[u] = index of u in the euler tour
	std::vector<int> out;  // out[u] = last index of the subtree of u

public:
	EulerTour(const std::vector<std::vector<int>> &graph, int _root = 0):
			n(graph.size()) {

		tour.reserve(n);
		in.resize(n);
		out.resize(n);
		p.resize(n);

		std::function<void(int)> dfs = [&](int u) -> void {
			tour.push_back(u);
			in[u] = tour.size() - 1;
			for (auto v: graph[u]) {
				if (v == p[u]) continue;
				p[v] = u;
				dfs(v);
			}
			out[u] = tour.size() - 1;
		};

		root = _root;
		p[root] = root;
		dfs(root);
	}
};
