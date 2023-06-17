#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n-1); for (auto &x: a) cin >> x;

	int l = 1, r = n;
	for (int i = 0; i < n-1; i++) {
		l += a[i]; r += a[i];
		l = max(1, l); r = min(n, r);
		if (l > r) { cout << -1; return; }
	}

	int start = l - accumulate(all(a), 0);

	vector<bool> used(n, false);
	used[start-1] = true;

	vector<int> ans = {start};

	for (int i = 0; i < n-1; i++) {
		start += a[i];
		if (used[start-1]) { cout << -1; return; }
		used[start-1] = true;
		ans.push_back(start);
	}

	for (const auto &x: ans) cout << x << ' ';
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
