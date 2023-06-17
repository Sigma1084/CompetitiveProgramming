#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int k; cin >> k;
	array<int, 6> f;
	for (auto &x: f) cin >> x;

	vector<pair<ll, int>> value(6);
	for (ll i = 0, v = 1e5; i < 6; i++, v /= 10)
		value[i] = { f[i] * v, i };
	sort(all(value));

	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		ll ans = 0;
		for (int i = 5; i >= 0; i--) {
			// How many times can we add the current value
			// We need to get rid of n
		}

		cout << ans << '\n';
	}

	return 0;
}
