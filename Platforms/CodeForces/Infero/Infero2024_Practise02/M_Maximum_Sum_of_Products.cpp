#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<ll> a(n); for (ll &x: a) cin >> x;
	vector<ll> b(n); for (ll &x: b) cin >> x;

	ll ans = 0, cur = 0;
	vector<ll> pref(n + 1);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + a[i] * b[i];
	}

	ans = pref.back();
	for (int i = 1, l, r; i < 2 * n - 1; i++) {
		cur = i & 1 ? 0 : a[i/2] * b[i/2];
		l = (i - 1) / 2, r = (i + 2) / 2;
		for (; l >= 0 and r < n; l--, r++) {
			cur += a[l] * b[r] + a[r] * b[l];
			ans = max(ans, cur + pref[l] +
				pref.back() - pref[r + 1]
			);
		}
	}

	cout << ans << endl;

	return 0;
}