#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
constexpr int P = 998244353;

template <class T>
T _pow(T a, int64_t b) { T ans = 1; for (; b; b /= 2, a *= a) if (b % 2) ans *= a; return ans; }

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
	vector<int> a(n); for (auto &x: a) cin >> x;
	
	int totZero = n - accumulate(all(a), 0);  // Total number of zeros
	int reqZero = totZero - accumulate(a.begin(), a.begin() + totZero, 0);
	vector<Z> dp(totZero + 1);  // for number of zeros in the first Z positions
	dp[totZero] = 0;

	for (int curZero = totZero - 1; curZero >= reqZero; curZero--) {
		// dp[curZero] = 1 + ( p*dp[curZero+1] ) + ( (1-p)*dp[curZero] )
		Z p = Z(totZero - curZero) * (totZero - curZero) / ( Z(n) * (n-1) / 2 );
		dp[curZero] = ( 1 + p * dp[curZero + 1] ) / p;
	}

	cout << dp[reqZero];
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

