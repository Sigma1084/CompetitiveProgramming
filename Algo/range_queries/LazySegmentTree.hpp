#include <vector>
#include <cmath>
#include <array>
#include <numeric>

/**
 * @brief A segment tree that supports range queries and range updates.
 * @details U() should be the identity element of the update.
 * @tparam T The type of the elements in the array
 * @tparam U The type of updates
 */
template <typename T, typename U = T>
class LazySegmentTree {
protected:
	const int n;  // The size of the array
	std::vector<T> tree;  // The segment tree
	std::vector<U> lazy;  // Stores the updates
	std::vector<int> nL, nR;  // Stores the bounds of each node

	// The below functions to be implemented by the user
	virtual T merge(T t1, T t2) = 0;
	virtual U& mergeUpdate(U& update, U newUpdate) = 0;
	virtual void consume(int node) = 0;

	/**
	 * @brief Checks if the node is completely out the range
	 * @param node Current node
	 * @param l Left limit
	 * @param r Right limit
	 * @return true if the node is out of the range
	 */
	constexpr bool outOfRange(int node, int l, int r) const {
		return nR[node] < l or r < nL[node];
	}

	/**
	 * @brief Checks if the node is completely in the range
	 * @param node Current node
	 * @param l Left limit
	 * @param r Right limit
	 * @return true if the node is completely in the range
	 */
	constexpr bool completelyInRange(int node, int l, int r) const {
		return l <= nL[node] and nR[node] <= r;
	}

	/**
	 * @brief Checks if the node is a leaf
	 * @param node Current node
	 * @return true if the node is a leaf
	 */
	constexpr bool isLeaf(int node) const {
		return node >= n;
	}

	/**
	 * @brief Number of elements represented by the node
	 * @param node Current node
	 * @return Number of elements represented by the node
	 */
	constexpr int sizeOf(int node) const {
		return nR[node] - nL[node] + 1;
	}

private:
	/**
	 * @brief Pushes the value of the lazy node to its children
	 * @param node The current node
	 */
	void push(int node) {
		if (lazy[node] == lazy[0]) return;  // Nothing to push

		// Propagate the update to the children
		if (!isLeaf(node)) {
			mergeUpdate(lazy[node * 2], lazy[node]);
			mergeUpdate(lazy[node * 2 + 1], lazy[node]);
		}

		consume(node);  // Consume the update
		lazy[node] = lazy[0];  // Clear the update
	}

	/**
	 * @brief Pulls the value of the children to the current node
	 * @param node The current node
	 */
	void pull(int node) {
		tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
	}

	/**
	 * @brief Queries the range [l, r]
	 * @param node The current node
	 * @param l The left bound of the query
	 * @param r The right bound of the query
	 */
	T _query(int node, int l, int r) {
		push(node);  // Updating the current node

		if (outOfRange(node, l, r)) return tree[0];
		if (completelyInRange(node, l, r)) return tree[node];

		return merge(_query(node * 2, l, r),
			_query(node * 2 + 1, l, r));
	}

	/**
	 * @brief Updates the range [l, r] by val
	 * @param node The current node
	 * @param val The value to update by
	 * @param l The left bound of the update
	 * @param r The right bound of the update
	 */
	void _update(int node, U update, int l, int r) {
		// The fact that update is called means there will be a pull
		push(node);  // Have to push before updating

		if (outOfRange(node, l, r)) return;  // node out of range

		if (completelyInRange(node, l, r)) {
			// Perfect overlap.
			lazy[node] = update;
			push(node);
		} else {
			// Partial overlap.
			_update(node * 2, update, l, r);
			_update(node * 2 + 1, update, l, r);
			pull(node);  // a pull is necessary after updating
		}
	}

public:
	/**
	 * @brief Initializes the tree with the given size
	 * @param _n The size of the array
	 * @param idElement The identity element of the elements
	 * @param idUpdate The identity element of the updates
	 */
	LazySegmentTree(int _n, T idElement = T(), U idUpdate = U()):
			n(1 << static_cast<int>(ceil(log2(_n)))) {
		tree.resize(2 * n, idElement);
		lazy.resize(2 * n, idUpdate);
		nL.resize(2 * n);
		nR.resize(2 * n);

		std::iota(nL.begin() + n, nL.end(), 0);
		std::iota(nR.begin() + n, nR.end(), 0);

		for (int i = n - 1; i > 0; i--) {
			nL[i] = nL[2 * i];
			nR[i] = nR[2 * i + 1];
		}
	};

	/**
	 * @brief Initializes the tree with the given vector
	 * @param v The vector to initialize the tree with
	 * @param idElement The identity element of the elements
	 * @param idUpdate The identity element of the updates
	 */
	template<class V>
	void assign(const std::vector<V> &v) {
		std::copy(v.begin(), v.end(), tree.begin() + n);
		for (int node = n - 1; node > 0; node--) {
			tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
		}
	}

	/**
	 * @brief Queries the range [l, r]
	 * @param l The left bound of the query
	 * @param r The right bound of the query
	 */
	T query(int l, int r) {
		return _query(1, l, r);
	}

	/**
	 * @brief Adds val to all elements in the range [l, r]
	 * @param l The left bound of the update
	 * @param r The right bound of the update
	 * @param update The update
	 */
	void update(int l, int r, U update) {
		_update(1, update, l, r);
	}
};


// An example of a lazy segment tree
using T = long long;
using U = long long;
struct LazySegmentTreeAdd: LazySegmentTree<T, U> {
	constexpr static T idElement = 0;
	constexpr static U idUpdate = 0;

	LazySegmentTreeAdd(int n): LazySegmentTree<T, U>(n, idElement, idUpdate) {}
	LazySegmentTreeAdd(const std::vector<T> &v):
		LazySegmentTree<T, U>(v.size(), idElement, idUpdate) {
		assign(v);
	}

	/**
	 * @brief Merges two elements of the primary operation
	 * @param t1 Value 1
	 * @param t2 Value 2
	 * @return The result of merging the two values
	 */
	T merge(T t1, T t2) override {
		return t1 + t2;
	}

	/**
	 * @brief Merges two updates of the secondary operation
	 * @param update
	 * @param newUpdate
	 * @return The result of merging the two updates
	 */
	U& mergeUpdate(U& update, U newUpdate) override {
		return update += newUpdate;
	}

	/**
	 * @brief Consumes the update of the node
	 * @param node
	 */
	void consume(int node) override {
		tree[node] += sizeOf(node) * lazy[node];
	}
};
