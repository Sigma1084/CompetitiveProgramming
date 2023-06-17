#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 998244353;


template <class T>
T _pow(T a, long long int b) {
    T ans = 1;
    for (; b; b /= 2, a *= a) if (b % 2) res *= a;
    return ans;
}

template <unsigned int MOD>
struct ModInt {
    using ll = long long int;
    ll val = 0;
    ModInt<MOD>() = default;
    ModInt<MOD>(const ll &v): val((MOD + v%MOD) % MOD) {}
    ModInt<MOD>(const int &v): ModInt<MOD>((ll) v) {}
    void normalize() { if (val < 0) val += MOD; if (val > MOD) val -= MOD; }
    ModInt<MOD> operator - () const { return ModInt<MOD>(-val); }
    ModInt<MOD>& operator += (const ModInt<MOD> &a)
    { val += a.val; normalize(); return *this; }
    ModInt<MOD>& operator -= (const ModInt<MOD> &a)
    { val -= a.val; normalize(); return *this; }
    ModInt<MOD>& operator *= (const ModInt<MOD> &a)
    { (val *= a.val) %= MOD; return *this; }
    ModInt<MOD> inv() const { return _pow(*this, MOD-2); }
    ModInt<MOD>& operator /= (const ModInt<MOD> &a)
    { val *= a.inv(); return *this; }
    friend ModInt<MOD> operator + (const ModInt<MOD> &a, const ModInt<MOD> &b)
    { ModInt<MOD> ans = a; return ans += b; }
    friend ModInt<MOD> operator - (const ModInt<MOD> &a, const ModInt<MOD> &b)
    { ModInt<MOD> ans = a; return ans -= b; }
    friend ModInt<MOD> operator * (const ModInt<MOD> &a, const ModInt<MOD> &b)
    { ModInt<MOD> ans = a; ans *= b; return ans; }
    friend ModInt<MOD> operator / (const ModInt<MOD> &a, const ModInt<MOD> &b)
    { ModInt<MOD> ans = a; ans /= b; return ans; }
};
typedef ModInt<MOD> Z;


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;
	vector<Z> s(n+1);
	for (int i = 0; i < n; i++)
		s[i+1] = s[i] + a[i];
	
	/**
	 * F(i, j) = S(j) - S(i-1)
	 * 
	 * F^(i, j) = S^3(j) - S^3(i-1) + 3S(j)S^2(i-1) - 3S^2(i-1)S(j)
	 * 
	 * SUM(i=1, N) SUM(j=i, N) S^3(j)
	 * = N S^3(N) + (N-1) S^3(N-1) + ... + 1 S^3(1)
	 * 
	 * SUM(i=1, N) SUM(j=i, N) S^3(i-1)
	 * = SUM(i=1, N) (N-i+1) S^3(i-1)
	 * 
	 */

	Z ans = 0, t1 = 0, t2 = 0;

	for (int i = n; i >= 1; i--) {
		ans += i * s[i] * s[i] * s[i];
		ans -= (n-i+1) * s[i-1] * s[i-1] * s[i-1];
		t1 += s[i]; t2 += s[i] * s[i];
		ans += 3 * s[i-1] * s[i-1] * t1;
		ans -= 3 * s[i-1] * t2;
	}

	cout << ans.val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

