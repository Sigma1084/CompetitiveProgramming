#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	set s = set(a.begin(), a.end());
	a = vector(s.begin(), s.end());
	n = a.size();

	if (n <= 3) {
		cout << 0;
		return;
	}

	/**
	 * firstStart = 0 and thirdEnd = n - 1
	 * are initially fixed
	 * 
	 * We fix firstEnd
	 * secondStart = firstEnd + 1
	 * 
	 * We binary search over secondEnd 
	 * thirdStart = secondEnd + 1
	 */

	int ans = (a.back() - a.front() + 1) / 2;
	for (int fE = 0, l, u, sS, sE; fE < n - 2; fE++) {
		if ((a[fE] - a[0] + 1) / 2 > ans) break;
		l = fE + 1, u = n - 2, sS = fE + 1;
		while (l < u) {
			sE = (l + u) / 2;
			ans = min(ans, max({1, 2, 3}));
		}
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
