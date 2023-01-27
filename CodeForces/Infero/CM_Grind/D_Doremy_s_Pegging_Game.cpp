#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

int P = 1'000'000'007;

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



void solve() {
	int n; cin >> n >> P;

	vector<Z> fact(n + 1), factInv(n + 1); fact[0] = 1;
	for (int i = 1; i <= n; i++)
		fact[i] = fact[i-1] * i;
	for (int i = 0; i <= n; i++)
		factInv[i] = (Z) 1 / fact[i];

	Z ans = 0;

	// Assume things end with knot 1 and the second knot is d right from 1
	// m is the number of mid knots being there

	if (n % 2) {
		for (int d = 1; 2*d < n; d++) {
			for (int m = 0; m < d; m++) {
				ans += (Z) d * fact[n-3-m] * fact[d-1] * factInv[m] * factInv[d-1-m];
			}
		}
	} else {
		for (int d = 1; 2*d < n; d++) {
			for (int m = 0; m < d; m++) {
				ans += (Z) (d+1) * fact[n-3-m] * fact[d-1] * factInv[m] * factInv[d-1-m];
			}
		}
		ans += (Z) (n-2) * fact[n-3];  // The opposite case
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
