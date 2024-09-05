#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, k; cin >> n >> k;
	ll ans = 1;

	// Assuming k to be less than 30 since 1 << 30 is greater than 1e9
	k = min(k, 30);

	while (k) {
		// If he can not afford the k-th one, minus k
		if (n < (1 << (k - 1))) { k--; continue; }

		// Without the k-th one
		ans += (1 << (k - 1));

		// With the k-th one
		k--;
		n -= 1 << k;
	}

	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}

	return 0;
}
