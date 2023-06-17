#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	int m = 0, f = 0, u = 0, mf = 0, tot = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			u++;
		} else {
			// Total is m + f + u
			tot = m + f + u;
			m = tot / 2;
			f = tot - m;
			u = 0;
		}
		mf = m + f;
		for (int k = mf/2 - 8, l; k < mf/2 + 2; k++) {
			l = mf - k;
			if (l < 0 or k < 0) continue;
			ans = max(ans, (k + 1) / 2 + (l + 1) / 2 + u);
			// cerr << mf << ' ' << k << ' ' << l << ' ' << u << ' ' << ans << '\n';
		}
		ans = max(ans, (m + 1) / 2 + (f + 1) / 2 + u);
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
