#pragma once
#include <vector>

/**
 * A Fenwick Tree with operation +
 * @tparam T type overloaded with +
 */
template<typename T>
class Fenwick {
	const int n;
	std::vector<T> tree;
public:
	Fenwick(int n): n(n), tree(n) {}

	void add(int index, int delta) {
		for (; index < n; index |= index + 1) {
			tree[index] += delta;
		}
	}

	T sum(int r) {
		T res = 0;
		for (; r >= 0; (r &= r + 1) -= 1) {
			res += tree[r];
		}
		return res;
	}

	T sum(int l, int r) {
		if (l > r) return 0;
		return sum(r) - sum(l - 1);
	}
};
