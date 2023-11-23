#pragma once

#include <cmath>
#include <functional>
#include <numeric>
#include <stdexcept>
#include <vector>

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
	int K;
	std::vector<std::vector<T>> st;
	Merger merge;

	T query(int l, int r, int k) {
		return merge(st[k][l], st[k][r - (1 << k) + 1]);
	}

public:
	SparseTable() = default;
	SparseTable(const SparseTable<T> &st) = default;
	template<class V>
	SparseTable(const std::vector<V> &a, Merger merge) { build(a, merge); }

	template<class V>
	void build(const std::vector<V> &a, Merger _merge) {
		merge = _merge;
		K = std::__lg(a.size());

		st.resize(K + 1);
		std::size_t n = a.size();
		st[0].resize(n);
		std::copy(a.begin(), a.end(), st[0].begin());

		for (int i = 1; i <= K; i++) {
			st[i].resize(n - (1 << i) + 1);
			for (int j = 0; j < static_cast<int>(n - (1 << i) + 1); j++) {
				st[i][j] = merge(
					st[i - 1][j],
					st[i - 1][j + (1 << (i - 1))]
				);
			}
		}
	}

	const std::vector<std::vector<T>>& operator () () const {
		return st;
	}

	T query(int l, int r) {
		if (l > r) {
			throw std::invalid_argument("l must be <= r");
		} else {
			int k = std::__lg(r - l + 1);
			return merge(st[k][l], st[k][r - (1 << k) + 1]);
		}
	}
};
