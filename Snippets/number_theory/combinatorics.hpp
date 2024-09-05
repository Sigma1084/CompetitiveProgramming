#pragma once

#include <array>
using Z = double;

template<typename T, unsigned int N>
class Comb {
    std::array<T, N + 1> _fact, _invFact, _inv;

public:
    constexpr Comb() {
        _fact[0] = 1;
        for (int i = 1; i <= N; ++i) {
            _fact[i] = _fact[i - 1] * i;
        }
        _invFact[N] = _fact[N].inv();
        for (int i = N; i >= 1; --i) {
            _invFact[i - 1] = _invFact[i] * i;
            _inv[i] = _fact[i - 1] * _invFact[i];
        }
        _inv[0] = 1;
    }

    [[nodiscard]] inline constexpr T fact(unsigned n) const {
        return _fact[n];
    }

    [[nodiscard]] inline constexpr T invFact(unsigned n) const {
        return _invFact[n];
    }

    [[nodiscard]] inline constexpr T inv(unsigned n) const {
        return _inv[n];
    }

    [[nodiscard]] inline constexpr T perm(unsigned n, unsigned k) const {
        if (k > n) return T(0);
        return _fact[n] * _invFact[n - k];
    }

    [[nodiscard]] inline constexpr T comb(unsigned n, unsigned k) const {
        if (k > n) return T(0);
        return _fact[n] * _invFact[k] * _invFact[n - k];
    }
};
