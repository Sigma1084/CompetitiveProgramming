#include <modular.hpp>
#include <cassert>
#include <iostream>

constexpr unsigned int P = 1'000'000'007;
using Z = modular<long, P, __int128_t>;

int main() {
	Z a(1), b(2);
	assert(a() == 1);
	assert(b() == 2);

	assert(Z(P)() == 0);
	assert(Z(P - 1)() == P - 1);

	assert(long(1 + Z(P - 1)) == 0);
	assert(long(-a) == P - 1);

	std::cout << "All tests passed!";

	return 0;
}
