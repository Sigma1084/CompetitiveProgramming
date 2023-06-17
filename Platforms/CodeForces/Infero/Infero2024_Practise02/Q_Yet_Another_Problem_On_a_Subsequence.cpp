#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

constexpr int P = 998'244'353;

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
	Z inv() const { return pow(P - 2); }
	Z& operator += (Z a) { val += a.val; normalize(); return *this; }
	Z& operator -= (Z a) { val -= a.val; normalize(); return *this; }
	Z& operator *= (Z a) { val = (int64_t) val * a.val % P; return *this; }
	Z& operator /= (Z a) { return *this *= a.inv(); }
	Z& operator ++ (int) { return operator+=(1); }
	Z& operator -- (int) { return operator-=(1); }
	Z operator + (Z a) { return Z(*this) += a; }
	Z operator - (Z a) { return Z(*this) -= a; }
	Z operator * (Z a) { return Z(*this) *= a; }
	Z operator / (Z a) { return Z(*this) /= a; }
	bool operator == (Z a) const { return val == a.val; }
	bool operator != (Z a) const { return val != a.val; }
	bool operator < (Z a) const { return val < a.val; }
	bool operator > (Z a) const { return val > a.val; }
	friend std::ostream& operator << (std::ostream &o, Z m) { return o << m.val; }
	friend std::istream& operator >> (std::istream &i, Z m) { return i >> m.val; }
};

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (int &i: a) cin >> i;

	vector<vector<Z>> nCk(n + 1, vector<Z>(n + 1));
	for (int _n = 0; _n <= n; _n++) nCk[_n][0] = 1;
	for (int _n = 1; _n <= n; _n++) {
		for (int _k = 1; _k <= _n; _k++) {
			nCk[_n][_k] = nCk[_n - 1][_k - 1] * _n / _k;
		}
	}

	/**
	 * dp[i] := Number of subsequences that start from i-th position
	 * dpAfter[i] := dp[i] + dp[i + 1] + ... + dp[n - 1]
	 * 
	 * 3  11 12 13 14  15  16 17 18 19
	 * i = 0, j = 5, numBetween = j - i - 1
	 * We want 2 (a[i] - 1) numbers from j - i - 1
	 * 
	 * Then, we want any dp after 16
	 */
	vector<Z> dp(n), dpAfter(n);
	for (int i = n - 2; i >= 0; i--) {
		dpAfter[i] = dpAfter[i + 1];
		if (a[i] <= 0 or i + a[i] > n - 1) continue;
		dp[i] = nCk[n - i - 1][a[i]];
		for (int j = i + a[i]; j + 2 < n; j++) {
			dp[i] += nCk[j - i - 1][a[i] - 1] * dpAfter[j + 1];
		}
		dpAfter[i] += dp[i];
	}

	cout << dpAfter[0] << endl;

	return 0;
}
