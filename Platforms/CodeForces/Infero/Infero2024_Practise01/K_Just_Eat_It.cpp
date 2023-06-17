#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	ll total = accumulate(a.begin(), a.end(), 0LL);

	ll cur = 0, maxSum = 0;
	for (int i = 0; i + 1 < n; i++) {
		if (cur < 0) cur = 0;
		cur += a[i];
		maxSum = max(cur, maxSum);
	}

	cur = 0;
	for (int i = 1; i < n; i++) {
		if (cur < 0) cur = 0;
		cur += a[i];
		maxSum = max(cur, maxSum);
	}

	if (maxSum < total) {
		cout << "YES";
	} else {
		cout << "NO";
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
