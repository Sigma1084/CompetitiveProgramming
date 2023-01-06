#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int MOD = 998244353;


template <class T>
T _pow(T a, int64_t b) { T ans = 1; for (; b; b /= 2, a *= a) if (b % 2) ans *= a; return ans; }

template <unsigned int P = MOD>
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
	MI<P>& operator /= (const MI<P> &a) { x *= a.inv().x; return *this; }
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


void solve() {
	int n; cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	vector<vector<Z>> dp(n, vector<Z>(n));

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			cin >> a[i][j];

	// Setup base case
	for (int i = 0; i < n; i++) {
		if (a[i][i] == 2) {
			cout << 0;
			return;
		}
		a[i][i] = 1;
		dp[i][i] = 2;
	}

	// Setting ones from outside
	for (int d = n-1; d > 1; d--) {
		for (int i = 0; i+d < n; i++) {
			if (a[i][i+d] != 1) continue;
			if (a[i+1][i+d] == 2 or a[i][i+d-1] == 2) {
				cout << 0;
				return;
			} else {
				a[i+1][i+d] = 1;
				a[i][i+d-1] = 1;
			}
		}
	}

	// Setting twos from inside
	for (int d = 1; d+1 < n; d++) {
		for (int i = 0; i+d < n; i++) {
			if (a[i][i+d] != 2) continue;
			if (i-1 >= 0 and a[i-1][i+d] == 1) {
				cout << 0;
				return;
			} else if (i-1 >= 0) {
				a[i-1][i+d] = 2;
			}
			if (i+d+1 < n and a[i][i+d+1] == 1) {
				cout << 0;
				return;
			} else if (i+d+1 < n) {
				a[i][i+d+1] = 2;
			}
		}
	}

	for (int d = 1; d < n; d++) {
		for (int i = 0; i+d < n; i++) {
			// Here finding dp[i][i+d] using all the lower values
			if (a[i][i+d] == 1) {
				dp[i][i+d] = 2;
			} else if (a[i][i+d] == 0) {
				// Check the first and last
				if (a[i][i+d-1] == 1 or a[i+1][i+d] == 1) {
					dp[i][i+d] = 4;
				} else {
					dp[i][i+d] = dp[i+1][i+d] * 2;
				}
			} else {
				// Case when 2 Must occur 
				if (a[i][i+d-1] == 1 and a[i+1][i+d] == 1) {
					dp[i][i+d] = 0;
				} else if (a[i][i+d-1] == 1 or a[i+1][i+d] == 1) {
					dp[i][i+d] = 2;
				} else if (a[i][i+d-1] == 2) {
					dp[i][i+d] = dp[i][i+d-1] * 2;
					if (a[i+1][i+d] == 2) {
						dp[i][i+d] -= 2;
					}
				} else if (a[i+1][i+d] == 2) {
					dp[i][i+d] = dp[i+1][i+d] * 2;
				} else {
					// Both left and right are zeroes
					dp[i][i+d] = dp[i+1][i+d] * 2 - 2;
				}
			}
		}
	}

	cout << dp[0][n-1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

