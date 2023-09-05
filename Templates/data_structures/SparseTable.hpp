#pragma once

#include <vector>
#include <functional>

template<typename T>
class SparseTable {
	const int K;
	std::vector<std::vector<T>> st;
	using Merger = std::function<T(const T&, const T&)>;
	const Merger merger;
public:
	static T& min (const T &a, const T &b) { return std::min(a, b); }
	static T& max (const T &a, const T &b) { return std::max(a, b); }
	static T& gcd (const T &a, const T &b) { return std::gcd(a, b); }

	SparseTable(const std::vector<int> &a, int K, Merger _merger)
	: K(K), merger(_merger) {
		st.resize(K + 1);
		int n = a.size();
		st[0] = a;
		for (int i = 1; i <= K and (1 << i) <= n; i++)
			st[i].resize(n - (1 << i) + 1);
		for (int i = 1; i <= K; i++)
			for (int j = 0; j + (1 << i) <= n; j++)
				st[i][j] = merger(st[i-1][j], st[i-1][j + (1 << (i-1))]);
	}

	SparseTable(const std::vector<int> &a, Merger _merger)
	: SparseTable(a, std::log2(a.size()), _merger) {}

	const std::vector<std::vector<T>>& sparseTable () const { return st; }

	T rmq(int l, int r, int k) { return merger(st[k][l], st[k][r - (1<<k) + 1]); }
	T rmq(int l, int r) { return rmq(l, r, std::log2(r - l + 1)); }
};
