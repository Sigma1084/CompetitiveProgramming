#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, k; cin >> n >> k;
	vector<pair<int, int>> a(n); for (auto &[x, i]: a) cin >> x;
	vector<int> b(n); for (int &x: b) cin >> x;
	for (int i = 0; i < n; i++) a[i].second = i;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<int> ans(n);

	for (int i = 0; i < n; i++) {
		ans[a[i].second] = b[i];
	}

	for (int i: ans) cout << i << ' ';
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
