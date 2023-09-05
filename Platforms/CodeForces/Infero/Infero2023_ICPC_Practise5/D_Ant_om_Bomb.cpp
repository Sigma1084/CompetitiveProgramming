#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, k; cin >> n >> k;
	k = 1'000'000 - k;
	map<double, ll> m;

	for (int i = 0, x, y, p; i < n; i++) {
		cin >> x >> y >> p;
		m[sqrt(1.0 * x * x + 1.0 * y * y)] += p;
	}

	double ans = 0;
	for (auto [r, p]: m) {
		if (k <= 0) break;
		ans = r;
		k -= p;
	}

	if (k <= 0) {
		cout << setprecision(13) << ans;
	} else {
		cout << -1;
	}

	return 0;
}
