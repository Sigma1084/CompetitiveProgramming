#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

/**
 * T(n) = 2 * T(n / 2) + 2 n^2
 * T(n) = 4n^2 works
 * 
 * 4 n^2 = 2 * 4 n^2 / 4 + 2 n^2
 */

int ask(int l, int r) {
	if (l == r) return 0;
	cout << "? " << l << ' ' << r << endl;
	int x; cin >> x;
	return x;
}

void submit(int ans) {
	cout << "! " << ans << endl;
}

int solve(int l, int r) {
	if (l == r) {
		return l;
	}

	int m = (l + r) / 2;
	int x1 = solve(l, m);
	int x2 = solve(m + 1, r);

	// The answer is now x1 or x2
	if (ask(x1, x2) == ask(x1, x2 - 1)) {
		return x2;
	} else {
		return x1;
	}
}

void solve() {
	int n; cin >> n;
	submit(solve(1, n));
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve();
	}

	return 0;
}
