#pragma once

#include <stdexcept>
#include <type_traits>

template<class BaseType, BaseType MOD, class LongType = BaseType>
    requires std::is_integral_v<BaseType> && std::is_integral_v<LongType> &&
             (MOD > 0)
class modular {
    using ModType = modular<BaseType, MOD, LongType>;
    BaseType val;

    void normalize() {
        if (val < 0) val += MOD;
        if (val >= MOD) val -= MOD;
    }

public:
    constexpr modular() = default;

    template<class U>
    constexpr explicit(false) modular(const U &v) {
        val = (MOD + v % MOD) % MOD;
    }

    constexpr modular(const modular &m) = default;

    constexpr ModType operator-() const {
        return ModType(MOD - val);
    }

    constexpr BaseType operator()() const {
        return val;
    }

    constexpr explicit operator BaseType() const {
        return val;
    }

    /**
     * @brief Binary modular exponentiation
     * @tparam U Integral ModType
     * @param b Exponent
     * @return modular exponentiation
     */
    template<class U>
    ModType pow(U b) const {
        ModType ans = 1;
        for (ModType a = *this; b > 0; b /= 2, a *= a) {
            if (b % 2) {
                ans *= a;
            }
        }
        return ans;
    }

    constexpr ModType inv() const {
        if (val == 0) {
            throw std::runtime_error("modular::inv(): division by zero");
        }
        return pow(MOD - 2);
    }

    constexpr ModType &operator+=(ModType a) {
        val += a.val;
        normalize();
        return *this;
    }

    constexpr ModType &operator-=(ModType a) {
        val -= a.val;
        normalize();
        return *this;
    }

    constexpr ModType &operator*=(ModType a) {
        val = LongType(1) * val * a.val % MOD;
        return *this;
    }

    constexpr ModType &operator/=(ModType a) {
        return *this *= a.inv();
    }

    constexpr friend ModType operator+(ModType a, ModType b) {
        return a += b;
    }

    constexpr friend ModType operator-(ModType a, ModType b) {
        return a -= b;
    }

    constexpr friend ModType operator*(ModType a, ModType b) {
        return a *= b;
    }

    constexpr friend ModType operator/(ModType a, ModType b) {
        return a /= b;
    }
};
