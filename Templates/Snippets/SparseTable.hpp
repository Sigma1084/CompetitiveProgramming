#include <vector>
#include <functional>

template<typename T>
class SparseTable {
	const int K;
	std::vector<std::vector<T>> st;
	using Merger = std::function<T(T&, T&)>;
	const Merger merger;
public:
	static T& min (T &a, const T &b) { return a = std::min(a, b); }
	static T& max (T &a, const T &b) { return a = std::max(a, b); }
	static T& gcd (T &a, const T &b) { return a = std::gcd(a, b); }

	SparseTable(const std::vector<int> &a, int K, Merger _merger)
	: K(K), merger(_merger) {
		st.resize(K + 1);
		int n = a.size();
		st[0] = a;
		for (int i = 1; i <= K and n - (1 << i) + 1 > 0; i++)
			st[i].resize(n - (1 << i) + 1);
		for (int i = 1; i <= K; i++)
			for (int j = 0; j + (1 << i) <= n; j++)
				st[i][j] = merger(st[i-1][j], st[i-1][j + (1 << (i-1))]);
	}

	const std::vector<std::vector<T>>& sparseTable() const { return st; }

	T rmq(int l, int r, int k) { return merger(st[k][l], st[k][r - (1<<k) + 1]); }
	T rmq(int l, int r) { return rmq(l, r, std::log2(r - l + 1)) - 1; }
};
