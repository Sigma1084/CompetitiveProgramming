#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x: a) cin >> x;

	int cur = ~0, ans = 0;
	for (int x: a) {
		cur &= x;
		if (cur == 0) {
			ans++;
			cur = ~0;
		}
	}

	cout << max(1, ans);
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
