#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int P = 1e9 + 7;

constexpr ll N = 1e18;

ll& safeMultiply(ll &a, const ll &b) {
	__int128_t res = a; res *= b;
	if (res > N) a = 0;
	else a = res;
	return a;
}

void solve() {
	ll n; int k; cin >> n >> k;
	vector<ll> primes(k);
	for (ll &i: primes) cin >> i;

	ll ans = 0;

	for (int i = 1; i < (1 << k); i++) {
		int mul = -1; ll res = 1;
		for (int j = 0; j < k and res; j++) {
			if (i & (1 << j)) {
				mul *= -1;
				safeMultiply(res, primes[j]);
			}
		}
		if (res)
			ans += mul * n / res;
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i=1; i<=t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}

