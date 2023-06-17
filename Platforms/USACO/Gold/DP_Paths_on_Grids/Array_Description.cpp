#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

constexpr int P = 1000000007;

class Z {
	int val = 0;
	void normalize() { if (val < 0) val += P; if (val > P) val -= P; }
public:
	Z() = default;
	template<class T> Z(const T &v): val((P + v%P) % P) {}
	Z operator - () const { return Z(0) -= val; }
	int operator ()() const { return val; }
	Z pow(int64_t b) const {
		assert(b >= 0); Z ans = 1;
		for (Z a = *this; b; b /= 2, a *= a) if (b % 2) ans *= a;
		return ans;
	}
	Z inv() const { return pow(P-2); }
	Z& operator += (Z a) { val += a.val; normalize(); return *this; }
	Z& operator -= (Z a) { val -= a.val; normalize(); return *this; }
	Z& operator *= (Z a) { val = (int64_t) val * a.val % P; return *this; }
	Z& operator /= (Z a) { *this *= a.inv(); return *this; }
	Z& operator ++ (int) { return operator+=(1); }
	Z& operator -- (int) { return operator-=(1); }
	Z operator + (Z b) { return Z(*this) += b; }
	Z operator - (Z b) { return Z(*this) -= b; }
	Z operator * (Z b) { return Z(*this) *= b; }
	Z operator / (Z b) { return Z(*this) /= b; }
	bool operator == (Z a) const { return val == a.val; }
	bool operator != (Z a) const { return val != a.val; }
	bool operator < (Z a) const { return val < a.val; }
	bool operator > (Z a) const { return val > a.val; }
	friend std::ostream& operator << (std::ostream &o, Z m) { return o << m.val; }
	friend std::istream& operator >> (std::istream &i, Z &m) { return i >> m.val; }
};


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<int> a(n); for (int &x : a) cin >> x;

	/**
	 * dp[i][x] := Number of ways of filling the i-th element with x
	 */
	vector<vector<Z>> dp(n, vector<Z>(m + 2, 0));

	for (int x = 1; x <= m; x++) {
		if (a[0] == 0 or a[0] == x) {
			dp[0][x] = 1;
		}
	}

	for (int i = 1; i < n; i++) {
		for (int x = 1; x <= m; x++) {
			if (a[i] == 0 or a[i] == x) {
				dp[i][x] = dp[i - 1][x - 1] + dp[i - 1][x] + dp[i - 1][x + 1];
			}
		}
	}

	Z ans = accumulate(dp[n - 1].begin(), dp[n - 1].end(), Z(0));
	cout << ans;

	return 0;
}
