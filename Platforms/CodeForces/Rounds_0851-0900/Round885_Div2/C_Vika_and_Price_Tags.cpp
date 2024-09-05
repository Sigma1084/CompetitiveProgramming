#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (auto &x: a) cin >> x;
	for (auto &x: b) cin >> x;

	bool ok = true;
	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0 and b[i] == 0) continue;
		
		int x = a[i], y = b[i], v = 0;
		while (x) {
			y %= 2 * x;
			tie(x, y) = make_pair(y, abs(x - y));
			v = (v + 1) % 3;
		}

		if (ans != -1 and ans != v)
			ok = false;
		ans = v;
	}

	cout << (ok ? "YES" : "NO");
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
