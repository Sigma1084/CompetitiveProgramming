#include <bits/stdc++.h>
using namespace std;

constexpr int P = 1'000'000'007;

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


constexpr int maxN = 200'000;
std::array<Z, maxN + 1> pow2;


constexpr int N = 7;  // Number of bits

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto &i: a) cin >> i;

	Z ans = 0;

	// At least k - At least k + 1 + At least k + 2 and so on
	for (int mask = 0; mask < (1 << N); mask++) {
		int sz = bitset<N>(mask).count();  // Number of bits
		if (sz < k) continue;
		// Frequency of the numbers that vibe with mask
		int f = count_if(a.begin(), a.end(), [mask](int i) { return (mask & i) == mask; });

		// If anything other than this mask is contained, that will spoil shit
		// The ways of including the other stuff is 2 ^ (k)
		if ((sz - k) % 2 == 0) {
			ans += pow2[f] - 1;
		} else {
			ans -= pow2[f] - 1;
		}
	}

	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	pow2[0] = 1;
	for (int i = 1; i <= maxN; i++)
		pow2[i] = pow2[i-1] * 2;

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}

	return 0;
}
