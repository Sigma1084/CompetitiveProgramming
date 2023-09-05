#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n); for (auto &x: a) cin >> x;

	vector<int> ps(n + 1);  // ps[i] = a[0] + ... + a[i-1]
	for (int i = 0; i < n; i++)
		ps[i + 1] = (ps[i] + a[i]) % k;

	for (int p: ps) cerr << p << ' ';
	cerr << '\n';

	int ans = 0;
	vector<int> nextOcc(k, -1);
	for (int i = n - 1; i >= 0; i--) {
		nextOcc[ps[i + 1]] = i;
		ans = max(ans, nextOcc[ps[i]] - i);
		for (int i: nextOcc) cerr << i << ' ';
		cerr << '\n';
	}
	cerr << '\n';

	if (ans == 0) ans--;
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
