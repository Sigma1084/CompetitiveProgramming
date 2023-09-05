#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

constexpr int N = 3e6;

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


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	multiset<int> ms;
	int n; cin >> n;
	for (int i = 0, x; i < 2 * n; i++) {
		cin >> x;
		ms.insert(x);
	}

	updatePrimes();

	for (int i = 0; i < n; i++) {
		int x = *ms.rbegin();
		/**
		 * If x is prime, then a prime created it
		 * Else x and x / lPF[x] are present
		 */
		if (isPrime[x]) {
			int p = lower_bound(primes.begin(), primes.end(), x) - primes.begin() + 1;
			cout << p << ' ';
			ms.erase(ms.find(x));
			ms.erase(ms.find(p));
		} else {
			int p = lPF[x];
			cout << x << ' ';
			ms.erase(ms.find(x));
			ms.erase(ms.find(x / p));
		}
	}
	cout << endl;

	return 0;
}
