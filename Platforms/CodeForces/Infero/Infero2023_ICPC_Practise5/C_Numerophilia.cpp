#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

constexpr int N = 1e5;

bool isPrime[N + 1];
std::vector<int> primes;
int lPF[N + 1];  // Least Prime Factor

void updatePrimes() {
	for (int i = 0; i <= N; i++) {
		lPF[i] = i;
		isPrime[i] = true;
	}
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= N; i++) {
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= N; j += i) {
			isPrime[j] = false;
			if (lPF[j] == j) lPF[j] = i;
		}
	}
	for (int i = 2; i <= N; i++)
		if (isPrime[i]) primes.push_back(i);
}


void solve() {
	int d; cin >> d;

	/**
	 * @brief
	 * 1 p1, p2, p1 * p2
	 * p1 > d and p2 - p1 > d
	 * Answer is p1 * p2
	 */

	int p1, p2;
	p1 = *lower_bound(primes.begin(), primes.end(), 1 + d);
	p2 = *lower_bound(primes.begin(), primes.end(), p1 + d);
	cout << 1LL * p1 * p2;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	updatePrimes();

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}

	return 0;
}
