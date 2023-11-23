#pragma once

#include <array>

template<typename T, unsigned int N>
class Combinatorics {
    std::array<T, N + 1> _fact, _invFact;

    void precompute() {
        _fact[0] = 1;
        for (unsigned int i = 1; i <= N; ++i) {
            _fact[i] = _fact[i - 1] * i;
        }
        _invFact[N] = T(1) / _fact[N];
        for (unsigned int i = N; i >= 1; --i) {
            _invFact[i - 1] = _invFact[i] * i;
        }
    }

public:
    constexpr Combinatorics() {
        precompute();
    }

    [[nodiscard]] constexpr T fact(int n) const {
        return _fact[n];
    }

    [[nodiscard]] constexpr T invFact(int n) const {
        return _invFact[n];
    }

    [[nodiscard]] constexpr T nCr(unsigned int n, unsigned int r) const {
        return _fact[n] * _invFact[r] * _invFact[n - r];
    }

    [[nodiscard]] constexpr T nPr(unsigned int n, unsigned int r) const {
        return _fact[n] * _invFact[n - r];
    }
};

using Z = double;

constexpr unsigned N = 1e6;
Combinatorics<Z, N> C;
