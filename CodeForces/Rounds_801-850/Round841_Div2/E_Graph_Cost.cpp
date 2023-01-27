#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


constexpr int N = 1e6;

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


/**
 * Decide to add weight = largest prime.
 * if gcd = g
 * Then, we will connect g with all it's multiples
 */

constexpr ll N2 = (N + 3) / 2;
ll maxAttainable[N2 + 1];

void solve() {
	int n; ll m; cin >> n >> m;
	// Say our gcd = k+1 and the maximum we can connect is maxAttainable[n/(k+1)]
	ll ans = 0;

	for (int k = (n + 3) / 2; k >= 1 and m; k--) {
		ll maxVertices = n / (k + 1);
		ll maxEdges = maxAttainable[maxVertices];
		ll numGroupsAdded = min(maxEdges / k, m / k);
		ans += (ll) numGroupsAdded * (k+1);  // with costPerEdge = 1 / (k+1)
		m -= numGroupsAdded * k;
	}

	if (m) {
		cout << -1;
	} else {
		cout << ans;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	updatePrimes();

	maxAttainable[0] = maxAttainable[1] = 0;
	for (int n = 2; n <= N2; n++) {
		// We add phi(n)
		ll phi = n;
		for (int x = n; x > 1; ) {
			int p = lPF[x];
			phi = phi * (p - 1) / p;
			while (x > 1 and x % p == 0)
				x /= p;
		}
		maxAttainable[n] = maxAttainable[n-1] + phi;
	}

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
