#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;
	vector<int> b(n); for (auto &x: b) cin >> x;
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		c[i] = a[i] - b[i];
	}

	int x = *max_element(c.begin(), c.end());

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (x == c[i]) {
			ans.push_back(i + 1);
		}
	}

	cout << ans.size() << '\n';
	for (int y: ans) {
		cout << y << ' ';
	}
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
