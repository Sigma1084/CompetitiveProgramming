#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
	ll n; cin >> n;
	ll ans = 0;
	ll inv2 = (MOD + 1) / 2;

	/**
	 * Consider n = 9 for example
	 * i = 1
	 * 1  1 1 1 1 1 1 1 1 -> 9
	 * 1  2 3 4 5 6 7 8 9 -> 44
	 * 
	 * i = 2
	 * 2  2  2 2 -> 6
	 * 1  2  3 4 -> 7
	 * 
	 * i = 3
	 * 3 3  3 -> 3
	 * 1 2  3 -> 0
	 */

	for (ll i = 1; i*i <= n; i++) {
		ll lim = n / i;
		ll fullSum = (lim % MOD) * ((lim+1) % MOD ) % MOD * inv2 % MOD;
		ll delSum = i * (i+1) / 2 % MOD;
		(ans += i * (lim - (i-1)) % MOD) %= MOD;
		(ans += (fullSum - delSum)) %= MOD;
	}
	cout << ans;
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

