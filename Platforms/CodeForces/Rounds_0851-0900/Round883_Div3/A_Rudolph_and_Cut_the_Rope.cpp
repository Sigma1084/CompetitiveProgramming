#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<pair<int, int>> a(n);
	for (auto &[x, y]: a) cin >> x >> y;
	
	int ans = 0;
	for (auto [x, y]: a) {
		ans += x > y;
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
