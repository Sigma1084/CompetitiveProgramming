#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    ll n, m; cin >> n >> m;
    ll tMax = 0, fMax = 0, k = 1, kAns = 1;
    for (ll i = n; i%2 == 0; i /= 2, tMax++);
    for (ll i = n; i%5 == 0; i /= 5, fMax++);

    for (ll t = 1, f = 1; k <= m; t++, f++) {
        kAns = k;
        if (t > tMax) k *= 2;
        if (f > fMax) k *= 5;
    }

    ll ans = (m/kAns) * kAns * n;
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

