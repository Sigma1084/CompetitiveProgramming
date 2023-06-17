#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

constexpr int P = 1'000'000'007;

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


/**
 * After k chars, suppose we have s openings and e endings
 * if e > s at some point, clearly no
 * 
 * Otherwise, we are at (s, e)
 * The number of ways of reaching (n, n) going above the y = x line
 * will be the same as the number of paths going from (s, e) to (n-1, n+1)
 */

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	string ss; cin >> ss;

	if (n & 1) {
		cout << 0 << endl;
		return 0;
	}

	n >>= 1;

	int s = 0, e = 0;
	for (char &c: ss) {
		if (c == '(') s++;
		else e++;
		if (e > s or s > n) {
			cout << 0 << endl;
			return 0;
		}
	}

	if (s == n) {
		cout << 1 << endl;
		return 0;
	}

	int x = n-s, y = n-e;
	// ans = (x+y)C(x) - (x-1 + y+1)C(x-1)
	
	Z xFact = 1, yFact = 1, xPyFact = 1;
	for (int i = 2; i <= x; i++) xFact *= i;
	for (int i = 2; i <= y; i++) yFact *= i;
	for (int i = 2; i <= x+y; i++) xPyFact *= i;

	Z ans = xPyFact / (xFact * yFact) - (xPyFact / (xFact / x * yFact * (y+1)));
	cout << ans << endl;

	return 0;
}
