#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 1e9 + 7;

ll modPow(const ll &a, const ll &b, ll MOD=MOD) {
	if (b == 0) return 1;
	ll ans = modPow(a, b/2, MOD);
	(ans *= ans) %= MOD;
	if (b % 2 == 1) (ans *= a) %= MOD;
	return ans;
}

ll fermetInv(const ll &x, ll MOD=MOD) {
	return modPow(x, MOD-2, MOD);
}

/**
 * @brief Prints the number, sum and product of all factors
 */
void solve() {
	int n; cin >> n;
	map<ll, ll> a;
	for (int i = 0; i < n; i++) {
		int x, k;
		cin >> x >> k;
		a[x] = k;
	}

	ll nF = 1, sF = 1, pF = 1;
	ll nFP = 1;

	/**
	 * For Sum of Factors
	 * Multiply (1 + x + x^2 + ... x^k) = (x^(k+1) - 1) / (x-1)
	 * for every factor x
	 */

	/**
	 * Raise the prodSoFar to the power k+1
	 * Multiply the prodSoFar to p^numSoFar(k+1C2)
	 */
	for (auto &[x, k]: a) {
		(nF *= (k + 1)) %= MOD;
		(sF *= (modPow(x, k+1) - 1) * fermetInv(x-1) % MOD) %= MOD;
		pF = modPow(pF, k+1);
		(pF *= modPow(x, (k*(k+1)/2) % (MOD-1) * nFP % (MOD-1))) %= MOD;
		(nFP *= (k + 1)) %= (MOD-1);
	}

	cout << nF << ' ' << sF << ' ' << pF;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

