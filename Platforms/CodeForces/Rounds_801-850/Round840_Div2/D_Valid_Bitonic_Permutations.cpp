#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int P = 1e9 + 7;

template <class T>
T _pow(T a, long long int b) { T ans = 1; for (; b; b /= 2, a *= a) if (b % 2) ans *= a; return ans; }

template <unsigned int P = P>
struct MI {
	using ll = long long int;
	ll x = 0;
	MI() = default;
	MI(const ll &v): x((P + v%P) % P) {}
	MI(const int &v): MI<P>((ll) v) {}
	void normalize() { if (x < 0) x += P; if (x > P) x -= P; }
	MI<P> operator - () const { return MI<P>(-x); }
	MI<P> operator ++ (int) { return operator+=(1); }
	MI<P> operator -- (int) { return operator-=(1); }
	MI<P>& operator += (const MI<P> &a) { x += a.x; normalize(); return *this; }
	MI<P>& operator -= (const MI<P> &a) { x -= a.x; normalize(); return *this; }
	MI<P>& operator *= (const MI<P> &a) { (x *= a.x) %= P; return *this; }
	MI<P> inv() const { return _pow(*this, P-2); }
	MI<P>& operator /= (const MI<P> &a) { (x *= a.inv().x) %= P; return *this; }
	bool operator == (const MI<P> &a) { return x == a.x; }
	bool operator != (const MI<P> &a) { return x != a.x; }
	friend MI<P> operator + (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans += b; }
	friend MI<P> operator - (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans -= b; }
	friend MI<P> operator * (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans *= b; }
	friend MI<P> operator / (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans /= b; }
	friend std::ostream& operator << (std::ostream &o, const MI<P> &m) { return o << m.x; }
	friend std::istream& operator >> (std::istream &i, MI<P> &m) { return i >> m.x; }
};
typedef MI<> Z;


const int N = 100;
vector<vector<Z>> nCk(N+1, vector<Z>(N+1));

Z comb(int n, int k) {
	if (n < 0 or k < 0 or k > n) return 0;
	return nCk[n][k];
}

void solve() {
	int n, i, j, x, y;
	cin >> n >> i >> j >> x >> y;

	Z ans = 0, outer; int rem;
	if (x == n) {
		if (i > 1 and i < n)
			ans = comb(n-y-1, j-i-1) * comb(y-1, n-j);
	} else if (y == n) {
		if (j > 1 and j < n)
			ans = comb(n-x-1, j-i-1) * comb(x-1, i-1);
	} else {
		if (x < y) {
			swap(x, y);
			j = n-j + 1;
			i = n-i + 1;
			swap(i, j);
		}

		for (int m = 2; m < i; m++) {
			ans += comb(n-x-1, i-m-1) * comb(x-y-1, j-i-1) * comb(y-1, n-j);
		}

		// Outer is possible
		outer = comb(y-1, n-j);
		rem = y-1 - (n-j);
		if (rem <= i-1) {
			// Now, we can vary m in between
			outer *= comb(x-y-1, i-1-rem);
			for (int m = i+1; m < j; m++) {
				ans += outer * comb(n-x-1, m-i-1);
			}
		}
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int n = 0; n <= N; n++) {
		nCk[n][0] = 1;
		for (int k = 1; k <= n; k++)
			nCk[n][k] = nCk[n-1][k-1] * n / k;
	}

	for (int i=1; i<=t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}

