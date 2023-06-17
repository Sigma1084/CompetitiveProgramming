#include <bits/stdc++.h>

template<typename T>
class SegTree {
	using Merger = std::function<T&(T&, const T&)>;
	const int init;
	int n;
	std::vector<T> a;
	const Merger merger;

	static T& add (T &a, const T &b) { return a += b; }
	static T& min (T &a, const T &b) { return a = std::min(a, b); }
	static T& max (T &a, const T &b) { return a = std::max(a, b); }
	static T& gcd (T &a, const T &b) { return a = std::gcd(a, b); }

public:
	SegTree(int _n, Merger _merger = add, T init = T()):
		n(1 << (int)ceil(log2(_n))), init(init), merger(_merger) {
		if (merger == SegTree::add) init = T(0);
		else if (merger == SegTree::gcd) init = T(0);
		else if (merger == SegTree::max) init = T(0);
		else if (merger == SegTree::min) init = INT_MAX;
	}

	SegTree(const std::vector<T> &v, Merger _merger = add, T _init = T()):
		SegTree(v.size(), _merger, init) {
		for (int i = 0; i < v.size(); i++)
			a[i + n] = v[i];
		for (int i = n - 1; i; i--)
			merger(a[i] = a[2*i], a[2 * i + 1]);
	}

	void update(int i, const T &v) {
		for (int temp = n + i; temp; temp /= 2)
			merge(a[temp], v);
	}

	T query(int l, int r) {
		T res = init;
		for (l += n, r += n; l <= r; l /= 2, r /= 2) {
			if (l % 2 == 1) merge(res, a[l++]);
			if (r % 2 == 0) merge(res, a[r--]);
		}
		return res;
	}
};