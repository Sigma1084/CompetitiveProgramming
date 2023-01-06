#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

template <class T>
T _pow(T a, int64_t b) { T ans = 1; for (; b; b /= 2, a *= a) if (b % 2) ans *= a; return ans; }

int P = 1e9 + 7;
struct MI {
	using ll = int64_t;
	ll val = 0;
	MI() = default;
	MI(const ll &v): val((P + v%P) % P) {}
	MI(const int &v): MI((ll) v) {}
	void normalize() { if (val < 0) val += P; if (val > P) val -= P; }
	MI operator - () const { return MI(-val); }
	MI operator ++ (int) { return operator+=(1); }
	MI operator -- (int) { return operator-=(1); }
	int operator ()() const { return val; }
	MI& operator += (const MI &a) { val += a.val; normalize(); return *this; }
	MI& operator -= (const MI &a) { val -= a.val; normalize(); return *this; }
	MI& operator *= (const MI &a) { (val *= a.val) %= P; return *this; }
	MI inv() const { return _pow(*this, P-2); }
	MI& operator /= (const MI &a) { (val *= a.inv().val) %= P; return *this; }
	bool operator == (const MI &a) { return val == a.val; }
	bool operator != (const MI &a) { return val != a.val; }
	friend MI operator + (const MI &a, const MI &b) { MI ans = a; return ans += b; }
	friend MI operator - (const MI &a, const MI &b) { MI ans = a; return ans -= b; }
	friend MI operator * (const MI &a, const MI &b) { MI ans = a; return ans *= b; }
	friend MI operator / (const MI &a, const MI &b) { MI ans = a; return ans /= b; }
	friend std::ostream& operator << (std::ostream &o, const MI &m) { return o << m.val; }
	friend std::istream& operator >> (std::istream &i, MI &m) { return i >> m.val; }
};

typedef MI Z;



void solve() {
	int n; cin >> n >> P;

	vector<Z> fact(n + 1), factInv(n + 1); fact[0] = 1;
	for (int i = 1; i <= n; i++)
		fact[i] = fact[i-1] * i;
	for (int i = 0; i <= n; i++)
		factInv[i] = 1 / fact[i];

	Z ans = 0;

	// Assume things end with knot 1 and the second knot is d right from 1
	// m is the number of mid knots being there

	if (n % 2) {
		for (int d = 1; 2*d < n; d++) {
			for (int m = 0; m < d; m++) {
				ans += d * fact[n-3-m] * fact[d-1] * factInv[m] * factInv[d-1-m];
			}
		}
	} else {
		for (int d = 1; 2*d < n; d++) {
			for (int m = 0; m < d; m++) {
				ans += (d+1) * fact[n-3-m] * fact[d-1] * factInv[m] * factInv[d-1-m];
			}
		}
		ans += (n-2) * fact[n-3];  // The opposite case
	}

	ans *= n;  // Can end at any arbitary knot
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
