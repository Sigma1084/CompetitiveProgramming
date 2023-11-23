#include <modular.hpp>
#include <sieve.hpp>
#include <combinatorics.hpp>
#include <cassert>
#include <iostream>

constexpr unsigned int P = 1'000'000'007;
using Z = modular<int, P, long long>;

constexpr unsigned int N = 1e6;
Sieve<N> S;
Combinatorics<Z, N> C;

void basicPrimeTest() {
	assert(S.lPF(1) == -1);
	assert(S.lPF(2) == 2);
	assert(S.isPrime(2));
	assert(S.isPrime(3));
	assert(S.isPrime(5));
}

void basicFactTest() {
	Combinatorics<int, 5> c5;
	for (int i = 0, p = 1; i <= 5; ++i) {
		assert(c5.fact(i) == p);
		assert(C.fact(i)() == p);
		p *= i + 1;
	}
}

void stressTest() {
	constexpr int N1 = 1e6 + 1e4;
	Combinatorics<Z, N1> C1;
	for (int i = 0; i <= N; ++i) {
		assert(C1.fact(i)() == C.fact(i)());
		assert(C1.invFact(i)() == C.invFact(i)());
	}
}

int main() {
	basicPrimeTest();
	std::cerr << "Basic prime test passed!\n";

	basicFactTest();
	std::cerr << "Basic combinatorics test passed!\n";

	stressTest();
	std::cerr << "Stress test passed!\n";

	std::cout << "All tests passed!\n";
	return 0;
}
