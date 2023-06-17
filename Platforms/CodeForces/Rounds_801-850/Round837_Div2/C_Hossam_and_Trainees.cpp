#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

const int N = 1e9;

vector<int> primes;
void seive(int lim) {
	int n = ceil(sqrt(N));
	vector<bool> isPrime(n + 1, true);
	for (int i = 2; i*i <= n; i++) {
		if (!isPrime[i]) continue;
		for (int j = i*i; j <= n; j += i)
			isPrime[j] = false;
	}
	for (int i = 2; i <= n; i++)
		if (isPrime[i])
			primes.push_back(i);
}

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	int f;
	for (int &p: primes) {
		f = 0;
		for (int &i: a) {
			if (i % p == 0)
				f++;
			while (i % p == 0)
				i /= p;
		}
		if (f > 1) {
			cout << "YES";
			return;
		}
	}

	sort(a.begin(), a.end());

	for (int i = 0; i+1 < n; i++) {
		if (a[i] != 1 and a[i] == a[i+1]) {
			cout << "YES";
			return;
		}
	}

	cout << "NO";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	updatePrimes();
	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

