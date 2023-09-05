#include <vector>
#include <numeric>

constexpr int N = 1e6;

std::vector<bool> isPrime(N + 1);
std::vector<int> primes;
std::vector<int> lPF(N + 1);  // Least Prime Factor

void seive() {
	isPrime.assign(N + 1, true);
	std::iota(lPF.begin(), lPF.end(), 0);

	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= N; i++) {
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= N; j += i) {
			isPrime[j] = false;
			if (lPF[j] == j) lPF[j] = i;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (isPrime[i]) primes.push_back(i);
	}
}
