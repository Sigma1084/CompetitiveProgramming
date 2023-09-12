#include <functional>
#include <stack>
#include <vector>

class Tree {
protected:
	int n = 0;
	int root = -1;

	// Store the edges
	std::vector<std::vector<int>> edges;

	// DFS
	std::vector<int> parent;
	std::vector<int> depth;
	std::vector<int> subtreeSize;

	// Euler tour
	std::vector<int> _tour;  // tour[i] = i-th node in the euler tour
	std::vector<int> _in;    // in[u] = index of u in the euler tour
	std::vector<int> _out;   // out[u] = last index of the subtree of u

	/**
	 * @brief Depth First Search to build the Euler Tour
	 * @param u The current node
	 */
	void dfs(int u) {
		_tour.push_back(u);
		_in[u] = _tour.size() - 1;
		_out[u] = _tour.size() - 1;

		for (auto v: edges[u]) {
			if (v == parent[u]) continue;
			parent[v] = u;
			depth[v] = depth[u] + 1;
			dfs(v);
			subtreeSize[u] += subtreeSize[v];
			_tour.push_back(u);
			_out[u] = _tour.size() - 1;
		}
	}

public:
	Tree() = default;

	Tree(const Tree &et) = default;

	Tree(const std::vector<std::vector<int>> &edges, int _root = 0) {
		buildET(edges, _root);
	}

	/**
	 * @brief Build the Euler Tour
	 * @param _edges
	 * @param _root
	 */
	void buildET(const std::vector<std::vector<int>> &_edges, int _root = 0) {
		edges = _edges;
		n = edges.size();
		root = _root;

		_tour.reserve(2 * n - 1);
		_in.resize(n);
		_out.resize(n);
		parent.resize(n);
		depth.resize(n);
		subtreeSize.resize(n, 1);

		parent[root] = root;
		depth[root] = 0;
		dfs(root);
	}

	/**
	 * @brief Get the size of the tree
	 * @return size of the tree
	 */
	constexpr int size () const {
		return n;
	}

	const std::vector<std::vector<int>>& e = edges;

	const std::vector<int> &p = parent;
	const std::vector<int> &d = depth;
	const std::vector<int> &sz = subtreeSize;

	const std::vector<int> &tour = _tour;
	const std::vector<int> &in = _in;
	const std::vector<int> &out = _out;
};
