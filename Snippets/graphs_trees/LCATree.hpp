#include "../range_qeuries/SparseTable.hpp"
#include "Tree.hpp"

class LCATree: public Tree {
	SparseTable<int> rmq;
public:
	using Tree::Tree;

	void buildLCA() {
		if (root == -1) {
			throw std::runtime_error("Tree not built yet");
		} else if (rmq().empty()) {
			rmq.build(_tour, [&](int u, int v) -> int {
				return depth[u] < depth[v] ? u : v;
			});  // Range Min Query on depth
		}
	}

	int lca(int u, int v) {
		if (rmq().empty()) buildLCA();
		return rmq.query(std::min(_in[u], _in[v]),
			std::max(_out[u], _out[v]));
	}
};
