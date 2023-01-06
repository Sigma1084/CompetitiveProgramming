#include<bits/stdc++.h>

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