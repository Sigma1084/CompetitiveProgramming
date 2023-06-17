#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


template<typename T>
T binPow(T a, uint64_t b) {
	T m = T(1);
	for (; b; b /= 2, a *= a) {
		if (b & 1) {
			m *= a;
		}
	}
	return m;
}

constexpr int P = 1000000007;

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
	Z& operator /= (const Z &a) { return operator*=(a.inv()); }
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


class Matrix: public std::array<std::array<Z, 2>, 2> {
public:
	using Base = std::array<std::array<Z, 2>, 2>;
	using Base::Base;
	Matrix (int c) { (*this)[0][0] = (*this)[1][1] = c; }
	Matrix (const Base &b): Base(b) {}
	friend Matrix operator * (const Matrix &m1, const Matrix &m2) {
		Matrix ans;
		ans[0][0] = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
		ans[0][1] = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
		ans[1][0] = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
		ans[1][1] = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];
		return ans;
	}
	Matrix& operator *= (const Matrix &m) { return *this = *this * m; }
	friend std::ostream& operator << (std::ostream &o, const Matrix &m) {
		return o << m[0][0] << ' ' << m[0][1] << ' ' << m[1][0] << ' ' << m[1][1];
	}
};


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	uint64_t n; cin >> n;

	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	
	Matrix m = Matrix::Base { array<Z, 2>{1, 1}, array<Z, 2>{1, 0} };
	m = binPow(m, n - 1);
	cout << m[0][0] << endl;

	return 0;
}
