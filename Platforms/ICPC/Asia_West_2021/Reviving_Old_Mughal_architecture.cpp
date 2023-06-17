#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; ll x; cin >> n >> x;
	vector<int> e(n);
	for (int &i: e) cin >> i;

	vector<bool> sel(n);
	for (int i = 0; i < n; i++) {
		if (e[i] >= 0) {
			x += e[i];
			sel[i] = true;
		}
	}

	for (int i = n-1; i >= 0; i--) {
		if (not sel[i] and x + e[i] >= 0) {
			x += e[i];
			sel[i] = true;
		}
	}

	cout << accumulate(sel.begin(), sel.end(), 0) << '\n';
	for (int i = 0; i < n; i++) {
		if (sel[i]) cout << i + 1 << ' ';
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
