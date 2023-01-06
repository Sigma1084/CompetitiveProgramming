#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

constexpr int P = 1'000'000'007;

class Z {
	int val = 0;
	void normalize() { if (val < 0) val += P; if (val > P) val -= P; }
public:
	Z() = default;
	template<class T> Z(const T &v): val((P + v%P) % P) {}
	Z(const Z &z) = default;
	Z operator - () const { return Z(0) -= val; }
	int operator ()() const { return val; }
	Z pow(int64_t b) const {
		assert(b >= 0); Z ans = 1;
		for (Z a = *this; b; b /= 2, a *= a) if (b % 2) ans *= a;
		return ans;
	}
	Z inv() const { return pow(P-2); }
	Z& operator += (const Z &a) { val += a.val; normalize(); return *this; }
	Z& operator -= (const Z &a) { val -= a.val; normalize(); return *this; }
	Z& operator *= (const Z &a) { val = (int64_t) val * a.val % P; return *this; }
	Z& operator /= (const Z &a) { *this *= a.inv(); return *this; }
	Z& operator ++ (int) { return operator+=(1); }
	Z& operator -- (int) { return operator-=(1); }
	Z operator + (const Z &b) { return Z(*this) += b; }
	Z operator - (const Z &b) { return Z(*this) -= b; }
	Z operator * (const Z &b) { return Z(*this) *= b; }
	Z operator / (const Z &b) { return Z(*this) /= b; }
	bool operator == (const Z &a) const { return val == a.val; }
	bool operator != (const Z &a) const { return val != a.val; }
	bool operator < (const Z &a) const { return val < a.val; }
	bool operator > (const Z &a) const { return val > a.val; }
	friend std::ostream& operator << (std::ostream &o, const Z &m) { return o << m.val; }
	friend std::istream& operator >> (std::istream &i, Z &m) { return i >> m.val; }
};

constexpr int numBits = 32;

struct Trie {
	struct Node {
		int f;  // Frequency
		Node *links[2];
		Node(): f(0), links{nullptr, nullptr} {}
	};

	Node *root;

	Trie() {
		root = new Node();
	}

	void insert(int num) {
		Node *node = root;
		for (int i = numBits - 1; i >= 0; i--) {
			int bit = (num >> i) & 1;
			if (!node->links[bit]) node->links[bit] = new Node();
			node = node->links[bit];
			node->f += 1;
		}
	}

	void remove(int num) {
		Node *node = root;
		for (int i = numBits - 1; i >= 0; i--) {
			int bit = (num >> i) & 1;
			node = node->links[bit];
			node->f -= 1;
		}
	}

	int getMaxEle(int num) const {
		int ans = 0;
		Node *node = root;
		for (int i = numBits - 1; i >= 0; i--) {
			int bit = (num >> i) & 1;
			if (node->links[1-bit] and node->links[1-bit]->f > 0) {
				ans |= 1 << i;
				node = node->links[1-bit];
			} else {
				node = node->links[bit];
			}
		}
		return ans;
	}
};


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	vector<vector<int>> adj(n);
	for (int i = 0, u, v; i+1 < n; i++) {
		cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	adj[0].push_back(0);

	Z ans = 0, prob = 1;
	int curXor = 0, bestXor;
	vector<int> p(n, -1); p[0] = 0;
	Trie trie;

	function<void(int)> dfs = [&] (int u) {
		trie.insert(a[u]);
		curXor ^= a[u];

		if (adj[u].size() == 1) {
			bestXor = trie.getMaxEle(curXor);
			ans += prob * bestXor;
		} else {
			prob = prob / (adj[u].size() - 1);
			for (const int &v: adj[u]) {
				if (v != p[u]) {
					p[v] = u;
					dfs(v);
				}
			}
			prob = prob * (adj[u].size() - 1);
		}

		curXor ^= a[u];
		trie.remove(a[u]);
	};

	dfs(0);

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
