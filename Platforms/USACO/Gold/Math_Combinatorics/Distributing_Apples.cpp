#include <bits/stdc++.h>
using namespace std;

constexpr int P = 1000000007;

class Z {
	int val = 0;
	void normalize() { if (val < 0) val += P; if (val > P) val -= P; }
public:
	Z() = default;
	template<class T> Z(const T &v): val((P + v%P) % P) {}
	Z(const Z &z) = default;
	Z operator - () const { return Z(0) -= val; }
	constexpr int operator ()() const { return val; }
	Z pow(unsigned long long b) const {
		Z ans = 1;
		for (Z a = *this; b; b /= 2, a *= a) if (b % 2) ans *= a;
		return ans;
	}
	Z inv() const { return pow(P - 2); }
	Z& operator += (Z a) { val += a.val; normalize(); return *this; }
	Z& operator -= (Z a) { val -= a.val; normalize(); return *this; }
	Z& operator *= (Z a) { val = 1LL * val * a.val % P; return *this; }
	Z& operator /= (Z a) { return *this *= a.inv(); }
	Z& operator ++ (int) { return operator+=(1); }
	Z& operator -- (int) { return operator-=(1); }
	Z operator + (Z a) { return Z(*this) += a; }
	Z operator - (Z a) { return Z(*this) -= a; }
	Z operator * (Z a) { return Z(*this) *= a; }
	Z operator / (Z a) { return Z(*this) /= a; }
	constexpr bool operator == (Z a) const { return val == a.val; }
	constexpr bool operator != (Z a) const { return val != a.val; }
	friend ostream& operator << (ostream &os, Z a) { return os << a(); }
};

/**
 * n children and m apples
 * Consider n - 1 sticks and m apples.
 * Number of arrangements is (m + n - 1) choose (n - 1).
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	// We need to compute (n + m - 1) choose (n - 1).
	n--;  // Let us ensure n <= m
	if (m < n) {
		swap(n, m);
	}

	Z num = 1, den = 1;
	for (int i = 1; i <= n; i++) {
		num *= m + i;
		den *= i;
	}
	cout << num / den << '\n';

	return 0;
}