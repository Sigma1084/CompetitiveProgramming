#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	int ans = 1, i = 0;
	for (i = 0; i < n; i++) {
		if (a[i] != 1) break;
		ans ^= 1;
	}
	if (i == n) ans ^= 1;

	if (ans == 0) {
		cout << "Second";
	} else {
		cout << "First";
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
