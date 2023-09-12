#include "../RangeQueries/SparseTable.hpp"
#include "Tree.hpp"

/**
 * @brief Lowest Common Ancestor using Euler Tour
 * @details Uses RMQ on Euler Tour to find the LCA of two nodes
 */
class LCATree: public Tree {
	SparseTable<int> rmq;
public:
	using Tree::Tree;

	/**
	 * @brief Build the LCA table
	 * @details Uses RMQ on Euler Tour to build the LCA table
	 */
	void buildLCA() {
		if (root == -1) {
			throw std::runtime_error("Tree not built yet");
		} else if (rmq().empty()) {
			rmq.build(_tour, [&](int u, int v) -> int {
				return depth[u] < depth[v] ? u : v;
			});  // Range Min Query on depth
		}
	}

	/**
	 * @brief Returns the Least Common Ancestor of two nodes
	 * @param u
	 * @param v
	 * @return least common ancestor of u and v
	 */
	int lca(int u, int v) {
		if (rmq().empty()) buildLCA();
		return rmq.query(std::min(_in[u], _in[v]),
			std::max(_out[u], _out[v]));
	}
};
