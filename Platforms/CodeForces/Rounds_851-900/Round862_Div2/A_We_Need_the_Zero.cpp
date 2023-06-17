#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	int ans = 0, ones, zeros;
	for (int j = 0; j < 32; j++) {
		ones = 0; zeros = 0;
		for (int i: a) {
			if (i & (1 << j)) ones++;
			else zeros++;
		}
		if (ones % 2 == 0) {
			// Do nothing
		} else if (zeros % 2 == 0) {
			ans += 1 << j;
		} else {
			cout << -1;
			return;
		}
	}

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
