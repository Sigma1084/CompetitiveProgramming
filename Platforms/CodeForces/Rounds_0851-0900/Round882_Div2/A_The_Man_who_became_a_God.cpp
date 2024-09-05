#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n); for (auto &x: a) cin >> x;

	k--;
	vector<int> b(n - 1);
	for (int i = 0; i < n - 1; i++) {
		b[i] = abs(a[i + 1] - a[i]);
	}
	sort(b.begin(), b.end());

	ll ans = 0;
	for (int i = 0; i + k < n - 1; i++) {
		ans += b[i];
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
