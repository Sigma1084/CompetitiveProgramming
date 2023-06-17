#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

int P = 1'000'000'007;

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
	Z& operator ++ (int) { return operator+=(1); }
	Z& operator -- (int) { return operator-=(1); }
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


void solve() {
	int n; cin >> n >> P;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	set<Z> s;
	for (int i = 1; i <= n; i++)
		s.insert(a[i] - a.back());

	Z ans = P - 1;
	for (; s.count(ans) and ans != 0; ans -= 1)
		s.erase(ans);

	int finAns = ans();
	int i = n-1;
	while (a[i] == P-1) i--;
	s.insert(a[i] + 1 - a.back());  // We produce an extra
	if (i < n-1) s.insert(0 - a.back());  // We produce a 0 as well
	
	for (; s.count(ans) and ans != 0; ans -= 1)
		s.erase(ans);
	
	finAns = min(finAns, max(P - a.back(), ans()));
	
	cout << finAns;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
