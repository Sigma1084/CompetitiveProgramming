#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

constexpr int N = 3e5;

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
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;
	int s, t; cin >> s >> t; s--; t--;
	// Indexes are 0-based
	cout << (5^5 == 0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	updatePrimes();

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
