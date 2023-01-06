#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	// numOnesTill[i] := Number of ones in a in the range [0, 1, ... , i]
	vector<int> numOnesTill(n);
	for (int i = 0; i < n; i++) {
		if (i) numOnesTill[i] = numOnesTill[i-1];
		numOnesTill[i] += (a[i] == 1);
	}

	int totOnes = numOnesTill[n-1];
	vector<int> numZerosAfter(n);

	ll inv = 0;
	for (int i = 0; i < n; i++) {
		// Add the number of zeroes in [i+1, ... , n-1]
		numZerosAfter[i] = n-1-i - (numOnesTill[n-1] - numOnesTill[i]);
		if (a[i] == 1)
			inv += numZerosAfter[i];
	}

	ll ans = inv;
	for (int i = 0; i < n; i++) {
		// If you replace a 0 by 1, the ones before will lose their value
		// Also, the 0s after will gain value
		if (a[i] == 0) {
			ans = max(ans, inv - numOnesTill[i] + numZerosAfter[i]);
		}

		// If you repalce a 1 by a 0, the ones before will gain their value
		// Also, the 0s after will lose value
		// Extra -1 since the current one is also counted
		else {
			ans = max(ans, inv + (numOnesTill[i]-1) - numZerosAfter[i]);
		}
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

