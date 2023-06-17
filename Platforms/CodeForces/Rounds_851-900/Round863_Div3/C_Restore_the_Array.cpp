#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	vector<int> b(n - 1); for (auto &x: b) cin >> x;
	vector<int> a(n);

	a[0] = b[0];
	for (int i = 1; i < n - 1; i++) {
		if (a[i-1] < b[i-1]) a[i] = b[i-1];
		else a[i] = min(a[i-1], b[i]);
	}
	a[n-1] = b[n-2];

	for (int i: a) cout << i << ' ';
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
