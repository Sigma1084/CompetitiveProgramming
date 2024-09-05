#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> maxFrndAfter(n+1, n);
	for (int i = 0; i < m; i++) {
		int l, r; cin >> l >> r;
		if (r < l) swap(l, r);  // l <= r
		maxFrndAfter[l] = min(maxFrndAfter[l], r-1);
	}

	// Update the maxFrndAfter
	for (int i = n-1; i >= 1; i--) {
		maxFrndAfter[i] = min(maxFrndAfter[i], maxFrndAfter[i+1]);
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += maxFrndAfter[i] - i + 1;
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

