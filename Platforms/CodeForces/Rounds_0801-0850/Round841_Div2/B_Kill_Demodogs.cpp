#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


template <class T>
T _pow(T a, long long int b) { T ans = 1; for (; b; b /= 2, a *= a) if (b % 2) ans *= a; return ans; }

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

const int P = 1e9 + 7;
typedef MI<P> Z;

void solve() {
	int n; cin >> n;
	Z ans = Z(n) * (n + 1) * (2*n + 1) / 3;
	ans -= Z(n) * (n + 1) / 2;
	cout << ans*2022;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}

