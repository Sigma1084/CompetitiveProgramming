#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


constexpr int P = 998244353;

class Z {
	int val = 0;
	void normalize() { if (val < 0) val += P; if (val >= P) val -= P; }
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
	friend Z operator + (const Z &a, const Z &b) { return Z(a) += b; }
	friend Z operator - (const Z &a, const Z &b) { return Z(a) -= b; }
	friend Z operator * (const Z &a, const Z &b) { return Z(a) *= b; }
	friend Z operator / (const Z &a, const Z &b) { return Z(a) /= b; }
	bool operator == (const Z &a) const { return val == a.val; }
	bool operator != (const Z &a) const { return val != a.val; }
	bool operator < (const Z &a) const { return val < a.val; }
	bool operator > (const Z &a) const { return val > a.val; }
	friend std::ostream& operator << (std::ostream &o, const Z &m) { return o << m.val; }
	friend std::istream& operator >> (std::istream &i, Z &m) { return i >> m.val; }
};


constexpr int N = 1e6;

bool isPrime[N + 1];
std::vector<int> primes;
int lPF[N + 1];  // Least Prime Factor

void updatePrimes() {
	for (int i = 0; i <= N; i++) {
		lPF[i] = i;
		isPrime[i] = true;
	}
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= N; i++) {
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= N; j += i) {
			isPrime[j] = false;
			if (lPF[j] == j) lPF[j] = i;
		}
	}
	for (int i = 2; i <= N; i++)
		if (isPrime[i]) primes.push_back(i);
}


Z fact[N + 1];


void solve() {
	int n; cin >> n;
	vector<int> a(2*n); for (auto &x: a) cin >> x;

	map<int, int> freqs;
	for (int &i: a) {
		freqs[i]++;
	}

	Z ans = fact[n];
	for (const auto &[p, f]: freqs) ans /= fact[f];

	// Find coefficient of x^n in (1 + f_p_1 x) * (1 + f_p_2 x) * ... * (1 + f_p_k x)
	vector<Z> coeffs(n + 1, 0);
	coeffs[0] = 1;
	for (const auto &[p, f]: freqs) {
		if (not isPrime[p]) continue;
		for (int i = n; i >= 1; i--) {
			coeffs[i] += coeffs[i-1] * f;
		}
	}

	ans *= coeffs[n];
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	updatePrimes();
	fact[0] = 1;
	for (int i = 1; i <= N; i++)
		fact[i] = fact[i-1] * i;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
