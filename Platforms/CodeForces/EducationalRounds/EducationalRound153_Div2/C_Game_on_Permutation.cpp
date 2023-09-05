#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	int mW = n + 1;  // Minimum winning element seen so far
	int m = n + 1;  // Minimum element seen so far
	int ans = 0;

	for (int x: a) {
		if (x < m) {
			m = x;
		} else if (x < mW) {
			ans += 1;
			mW = x;
		}
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
