#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

const int N = 1e6+2;
vector<bool> isPrime(N, true);
// div[i] is the list of divisors of i
vector<int> divisors[N];

void compute() {
	for (int n = 2; n < N; n++) {
		if (!isPrime[n]) continue;
		// Now n is prime
		for (int m = n; m < N; m += n) {
			// Find max k such that n^k divides m
			int k = 0;
			for (int mCopy = m; mCopy%n == 0; mCopy /= n, k++);
			divisors[m].push_back(k);
			isPrime[m] = false;
		}
	}
}

void solve() {
	int x; cin >> x;
	int ans = 1;
	for (int &d: divisors[x]) {
		ans *= d+1;
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	compute();
	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

