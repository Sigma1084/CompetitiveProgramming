#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

template <class T>
T _pow(T a, int64_t b) { T ans = 1; for (; b; b /= 2, a *= a) if (b % 2) ans *= a; return ans; }

template <unsigned int P>
struct MI {
	using ll = int64_t;
	ll value = 0;
	MI() = default;
	MI(const ll &v): value((P + v%P) % P) {}
	MI(const int &v): MI<P>((ll) v) {}
	void normalize() { if (value < 0) value += P; if (value > P) value -= P; }
	MI<P> operator - () const { return MI<P>(-value); }
	MI<P> operator ++ (int) { return operator+=(1); }
	MI<P> operator -- (int) { return operator-=(1); }
	unsigned int operator ()() const { return value; }
	MI<P>& operator += (const MI<P> &a) { value += a.value; normalize(); return *this; }
	MI<P>& operator -= (const MI<P> &a) { value -= a.value; normalize(); return *this; }
	MI<P>& operator *= (const MI<P> &a) { (value *= a.value) %= P; return *this; }
	MI<P> inv() const { return _pow(*this, P-2); }
	MI<P>& operator /= (const MI<P> &a) { (value *= a.inv().value) %= P; return *this; }
	bool operator == (const MI<P> &a) { return value == a.value; }
	bool operator != (const MI<P> &a) { return value != a.value; }
	friend MI<P> operator + (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans += b; }
	friend MI<P> operator - (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans -= b; }
	friend MI<P> operator * (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans *= b; }
	friend MI<P> operator / (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans /= b; }
	friend std::ostream& operator << (std::ostream &o, const MI<P> &m) { return o << m.value; }
	friend std::istream& operator >> (std::istream &i, MI<P> &m) { return i >> m.value; }
};

const int P = 998244353;

typedef MI<P> Z;


void solve() {
	int n; ll m; cin >> n >> m;
	vector<int> a(n); for (auto &x: a) cin >> x;

	Z ans = 0, tot = 1, good = 1;  // ans = tot - good  for all i
	ll primeProd = 1;
	for (int i = 1; i <= n; i++) {
		if (gcd(primeProd, i) == 1)
			primeProd *= i;
		tot *= m;
		good *= m / primeProd;
		ans += tot - good;
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i=1; i<=t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
