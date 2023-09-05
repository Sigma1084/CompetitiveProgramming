#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


template<typename T>
class SegmentTree {
	int n;
	const T init;
	std::vector<T> a;

	using Merger = std::function<T(const T&, const T&)>;
	const Merger merger;

public:
	static T add (const T &a, const T &b) { return a + b; }
	static T min (const T &a, const T &b) { return std::min(a, b); }
	static T max (const T &a, const T &b) { return std::max(a, b); }
	static T gcd (const T &a, const T &b) { return std::gcd(a, b); }

	SegmentTree(int _n, Merger _merger = add, T _init = T()):
		merger(_merger), init(_init) {
			n = 1 << static_cast<int>(ceil(log2(_n)));
			a.assign(2 * n, init);
		}

	SegmentTree(const std::vector<T> &v, Merger _merger = add, T _init = T()):
		SegmentTree(v.size(), _merger, init) {
		for (int i = 0; i < static_cast<int>(v.size()); i++)
			a[i + n] = v[i];
		for (int i = n - 1; i; i--)
			a[i] = merger(a[2 * i], a[2 * i + 1]);
	}

	void update(int i, const T &v) {
		i += n; a[i] = v;
		for (i /= 2; i; i /= 2)
			a[i] = merger(a[2 * i], a[2 * i + 1]);
	}

	T at(int x) const {
		return a[x + n];
	}

	T query(int l, int r) const {
		T res = init;
		for (l += n, r += n; l <= r; l /= 2, r /= 2) {
			if (l % 2 == 1) res = merger(res, a[l++]);
			if (r % 2 == 0) res = merger(res, a[r--]);
		}
		return res;
	}

	void debug() {
		cerr << "Debug: ";
		for (T x: a) std::cerr << x << ' ';
		std::cerr << '\n';
	}
};


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m, q; cin >> n >> m >> q;
	string s; cin >> s;
	vector<int> _next(n + 1);
	iota(_next.begin(), _next.end(), 0);
	vector<int> order;

	int numOnes = 0;
	for (char c: s)
		numOnes += c - '0';

	function<int(int)> next = [&] (int x) -> int {
		if (_next[x] == x) return x;
		return _next[x] = next(_next[x]);
	};

	for (int i = 0, l, r; i < m; ++i) {
		cin >> l >> r; --l; --r;
		for (int x = next(l); x <= r; x = next(x + 1)) {
			order.push_back(x);
			_next[x] = r + 1;
		}
	}

	vector<int> invOrder(n, -1);
	string t;

	n = order.size();
	for (int i = 0; i < n; ++i) {
		invOrder[order[i]] = i;
		t += s[order[i]];
	}

	SegmentTree<int> st(n, SegmentTree<int>::add, 0);
	for (int i = 0; i < n; ++i) {
		st.update(i, int(t[i] - '0'));
	}

	int ans = min(numOnes, n) - st.query(0, min(n, numOnes) - 1);

	for (int i = 0, x; i < q; i++) {
		cin >> x; x--;
		s[x] == '1' ? numOnes-- : numOnes++;
		s[x] = '0' + (s[x] == '0');
		x = invOrder[x];

		// cerr << '\n';
		// cerr << "t: " << t << '\n';
		// cerr << "numOnes = " << numOnes << '\n';
		// cerr << "ans: " << ans << '\n';
		// cerr << "invX: " << x << '\n';

		if (x == -1) {
			cout << ans << '\n';
			continue;
		}

		t[x] = '0' + (t[x] == '0');
		st.update(x, 1 ^ st.at(x));
		ans = min(numOnes, n) - st.query(0, min(n, numOnes) - 1);
		cout << ans << '\n';
	}

	return 0;
}
