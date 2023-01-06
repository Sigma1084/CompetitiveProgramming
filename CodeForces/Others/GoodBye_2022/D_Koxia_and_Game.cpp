#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

constexpr int P = 998244353;

template <class T>
T _pow(T a, uint64_t b) { T ans = 1; for (; b; b /= 2, a *= a) if (b % 2) ans *= a; return ans; }

struct ModInt {
	int64_t val = 0;
	ModInt() = default;
	ModInt(const int64_t &v): val((P + v%P) % P) {}
	ModInt(const int &v): ModInt((int64_t) v) {}
	void normalize() { if (val < 0) val += P; if (val > P) val -= P; }
	ModInt operator - () const { return ModInt(-val); }
	ModInt operator ++ (int) { return operator+=(1); }
	ModInt operator -- (int) { return operator-=(1); }
	int operator ()() const { return val; }
	ModInt& operator += (const ModInt &a) { val += a.val; normalize(); return *this; }
	ModInt& operator -= (const ModInt &a) { val -= a.val; normalize(); return *this; }
	ModInt& operator *= (const ModInt &a) { (val *= a.val) %= P; return *this; }
	ModInt inv() const { return _pow(*this, P-2); }
	ModInt& operator /= (const ModInt &a) { (val *= a.inv().val) %= P; return *this; }
	bool operator == (const ModInt &a) { return val == a.val; }
	bool operator != (const ModInt &a) { return val != a.val; }
	friend ModInt operator + (const ModInt &a, const ModInt &b) { ModInt ans = a; return ans += b; }
	friend ModInt operator - (const ModInt &a, const ModInt &b) { ModInt ans = a; return ans -= b; }
	friend ModInt operator * (const ModInt &a, const ModInt &b) { ModInt ans = a; return ans *= b; }
	friend ModInt operator / (const ModInt &a, const ModInt &b) { ModInt ans = a; return ans /= b; }
	friend std::ostream& operator << (std::ostream &o, const ModInt &m) { return o << m.val; }
	friend std::istream& operator >> (std::istream &i, ModInt &m) { return i >> m.val; }
};

typedef ModInt Z;


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x, x--;
	vector<int> b(n); for (auto &x: b) cin >> x, x--;

	vector<vector<int>> e(n);
	for (int i = 0; i < n; i++) {
		e[a[i]].push_back(b[i]);
		e[b[i]].push_back(a[i]);
	}

	Z ans = 1;
	vector<bool> vis(n, false);

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		int numVert = 1, numEdges = 0;
		queue<int> q;

		q.push(i); vis[i] = true;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			numEdges += e[u].size();
			for (auto &v: e[u]) {
				if (not vis[v]) {
					vis[v] = true;
					numVert++;
					q.push(v);
				}
			}
		}

		numEdges /= 2;
		if (numVert == numEdges) {
			ans *= 2;
		} else {
			ans = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			ans *= Z(n) / 2;
		}
	}

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
