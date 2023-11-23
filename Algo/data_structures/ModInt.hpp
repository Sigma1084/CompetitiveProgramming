#pragma once
#include <iostream>

template<unsigned int P>
class ModInt {
	int val;

	void normalize() {
		if (val < 0) val += P;
		if (val >= P) val -= P;
	}

public:
	constexpr ModInt() = default;

	template<class T>
	constexpr explicit(false) ModInt(const T &v) {
		val = (P + v % P) % P;
	}

	constexpr ModInt(const ModInt &m) = default;

	constexpr ModInt<P> operator-() const {
		return ModInt<P>(P - val);
	}

	constexpr int operator()() const {
		return val;
	}

	constexpr explicit operator int() const {
		return val;
	}

	ModInt<P> pow(unsigned long long b) const {
		ModInt<P> ans = 1;
		for (ModInt<P> a = *this; b; b /= 2, a *= a) {
			if (b % 2) { ans *= a; }
		}
		return ans;
	}

	constexpr ModInt<P> inv() const {
		static_assert(val != 0, "ModInt<P>::inv(): division by zero");
		return pow(P - 2);
	}

	constexpr ModInt<P> &operator+=(ModInt<P> a) {
		val += a.val;
		normalize();
		return *this;
	}

	constexpr ModInt<P> &operator-=(ModInt<P> a) {
		val -= a.val;
		normalize();
		return *this;
	}

	constexpr ModInt<P> &operator*=(ModInt<P> a) {
		val = 1LL * val * a.val % P;
		return *this;
	}

	constexpr ModInt<P> &operator/=(ModInt<P> a) {
		return *this *= a.inv();
	}

	constexpr friend ModInt<P> operator+(ModInt<P> a, ModInt<P> b) {
		return a += b;
	}

	constexpr friend ModInt<P> operator-(ModInt<P> a, ModInt<P> b) {
		return a -= b;
	}

	constexpr friend ModInt<P> operator*(ModInt<P> a, ModInt<P> b) {
		return a *= b;
	}

	constexpr friend ModInt<P> operator/(ModInt<P> a, ModInt<P> b) {
		return a /= b;
	}

	friend std::ostream &operator<<(std::ostream &os, ModInt<P> a) {
		return os << a();
	}
};
