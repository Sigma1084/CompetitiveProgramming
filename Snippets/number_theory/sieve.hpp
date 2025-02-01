#pragma once

#include <array>
#include <numeric>
#include <vector>

namespace sieve {
template<unsigned int N>

constexpr std::array<unsigned int, N + 1> getLPF() {
    std::array<unsigned int, N + 1> lPF;
    std::iota(lPF.begin(), lPF.end(), 0);
    for (unsigned int i = 2; i * i <= N; ++i) {
        if (lPF[i] != i) continue;
        for (unsigned int j = i * i; j <= N; j += i) {
            if (lPF[j] == j) lPF[j] = i;
        }
    }
    return lPF;
}

template<unsigned int N>
std::vector<int> getPrimes(const std::array<unsigned int, N + 1> &_lPF) {
    std::vector<int> primes;
    for (unsigned int i = 2; i <= N; ++i) {
        if (_lPF[i] == i) {
            primes.push_back(i);
        }
    }
    return primes;
}

constexpr int N = 1'000'000;
const auto lPF = getLPF<N>();
const auto primes = getPrimes<N>(lPF);

}  // namespace sieve
using sieve::lPF, sieve::primes;
