#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

/**
 * @brief Returns a^b (mod MOD)
 */
int binaryExp(int a, int b, int MOD) {
	if (b == 0) return 1;
	if (a == 0) return 0;
	if (b == 1) return a;
	ll ans = binaryExp(a, b/2, MOD);
	ans = ans*ans % MOD;
	if (b % 2) ans = ans*a % MOD;
	return ans;
}

void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	/**
	 * We need a^(b^c) \n
	 * Using F.l.T (Fermat's little Theorem), \n
	 *   a^(MOD-1) = 1 (mod MOD) If gcd(a, MOD) = 1 \n
	 * Since a < MOD and MOD being a prime, gcd(a, MOD) = 1 \n
	 * Enough to calculate exp = b^c (mod MOD-1) \n
	 * Then a^exp (mod MOD)
	 */

	int exp = binaryExp(b, c, MOD-1);
	cout << binaryExp(a, exp, MOD);
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

