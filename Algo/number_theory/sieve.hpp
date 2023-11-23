#pragma once

#include <array>
#include <numeric>
#include <vector>

template<unsigned int N>
class Sieve {
	std::array<int, N + 1> _lPF;  // Least Prime Factor
	std::vector<int> primes;

	constexpr void sieve() noexcept {
		std::iota(_lPF.begin(), _lPF.end(), 0);
		_lPF[0] = _lPF[1] = -1;
		for (unsigned int i = 2; i * i <= N; ++i) {
			if (_lPF[i] != i) continue;
			for (unsigned int j = i * i; j <= N; j += i) {
				if (_lPF[j] == j) _lPF[j] = i;
			}
		}
		for (unsigned int i = 2; i <= N; ++i) {
			if (_lPF[i] == i) {
				primes.push_back(i);
			}
		}
	}

public:
	[[nodiscard]] constexpr bool isPrime(int n) const {
		return _lPF[n] == n;
	}

	[[nodiscard]] constexpr int lPF(int n) const {
		return _lPF[n];
	}

	[[nodiscard]] constexpr std::vector<int> factors(int n) const {
		std::vector<int> factors;
		while (n != 1) {
			factors.push_back(_lPF[n]);
			n /= _lPF[n];
		}
		return factors;
	}

	Sieve() {
		sieve();
	}
};
