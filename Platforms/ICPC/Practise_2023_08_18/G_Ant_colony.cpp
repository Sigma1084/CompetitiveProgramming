#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

struct SegTree {
	const int n;
	using T = pair<int, int>;
	vector<T> st;

	T merge(T p1, T p2) {
		if (p1.first == p2.first) {
			return {p1.first, p1.second + p2.second};
		}
		int g = gcd(p1.first, p2.first);
		if (p1.first == g) {
			return p1;
		} else if (p2.first == g) {
			return p2;
		} else {
			return {g, 0};
		}
	}

	SegTree(const vector<int> &a): n(1 << ((int)ceil(log2(a.size())))) {
		st.resize(2 * n);
		for (int i = 0; i < a.size(); i++) {
			st[n + i] = {a[i], 1};
		}
		for (int i = n - 1; i > 0; i--) {
			st[i] = merge(st[2*i], st[2*i + 1]);
		}
	}

	T query(int l, int r) {
		l += n; r += n;
		T ans = {0, 0};
		while (l <= r) {
			if (l % 2 == 1) ans = merge(ans, st[l++]);
			if (r % 2 == 0) ans = merge(ans, st[r--]);
			l /= 2; r /= 2;
		}
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;

	SegTree st(a);

	int nQ; cin >> nQ;
	for (int q = 0, l, r; q < nQ; q++) {
		cin >> l >> r;
		l--; r--;
		auto [g, f] = st.query(l, r);
		cout << r + 1 - l - f << '\n';
	}

	return 0;
}
