#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	ll ans = 0;
	for (int i: a) {
		ans += max(i, -i);
	}

	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}

	return 0;
}
