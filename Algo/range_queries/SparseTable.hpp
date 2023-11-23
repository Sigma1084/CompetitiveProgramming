#pragma once

#include <cmath>
#include <functional>
#include <numeric>
#include <stdexcept>
#include <vector>

/**
 * @brief Sparse Table
 *
 * Works on any set endowed with a binary commutative, associative
 * and idempotent operation.
 * <br>
 * We want to have op(x, x) = x for all x in the set.
 * eg: min, max, gcd, lcm, &, |
 *
 * @tparam T
 */
template<typename T>
class SparseTable {
public:
	using Merger = std::function<T(const T&, const T&)>;

	// A few examples of merge functions can be passed to the constructor
	static T min (const T &a, const T &b) { return std::min(a, b); }
	static T max (const T &a, const T &b) { return std::max(a, b); }
	static T gcd (const T &a, const T &b) { return std::gcd(a, b); }
	static T lcm (const T &a, const T &b) { return std::lcm(a, b); }
	static T bitAnd (const T &a, const T &b) { return a & b; }
	static T bitOr (const T &a, const T &b) { return a | b; }

private:
	int K{};
	std::vector<std::vector<T>> st;
	Merger merge;

public:
	/**
	 * @brief Default constructor
	 */
	SparseTable() = default;

	/**
	 * @brief Default copy constructor
	 */
	SparseTable(const SparseTable<T> &st) = default;

	/**
	 * @brief Construct a new Sparse Table object
	 * @tparam V The type of the elements in the vector
	 * @param a Vector to be processed
	 * @param merge The merge function
	 */
	template<class V>
	SparseTable(const std::vector<V> &a, Merger merge) {
		build(a, merge);
	}

	/**
	 * @brief Build the sparse table
	 * @param a Vector to be processed
	 * @tparam V The type of the elements in the vector
	 */
	template<class V>
	void build(const std::vector<V> &a, Merger _merge) {
		merge = _merge;
		K = std::log2(a.size());

		st.resize(K + 1);
		std::size_t n = a.size();
		st[0].resize(n);
		std::copy(a.begin(), a.end(), st[0].begin());

		for (int i = 1; i <= K; ++i) {
			st[i].resize(n - (1 << i) + 1);
			for (int j = 0; j < static_cast<int>(n - (1 << i) + 1); ++j) {
				st[i][j] = merge(
					st[i - 1][j],
					st[i - 1][j + (1 << (i - 1))]
				);
			}
		}
	}

	/**
	 * @brief Get the sparse table object for debugging
	 * @return A const reference to the sparse table
	 */
	const std::vector<std::vector<T>>& operator () () const {
		return st;
	}

	/**
	 * @brief Range Query in O(1)
	 * @param l Left index of the query
	 * @param r Right index of the query
	 * @return The result of the query
	 */
	[[maybe_unused]] [[nodiscard]]
	T query(int l, int r) {
		if (l > r) {
			throw std::invalid_argument("l must be <= r");
		} else {
			int k = std::__lg(r - l + 1);
			return merge(st[k][l], st[k][r - (1 << k) + 1]);
		}
	}
};
