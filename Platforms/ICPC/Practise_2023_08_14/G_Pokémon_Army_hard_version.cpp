#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n); for (auto &x: a) cin >> x;

	if (n == 1) {
		cout << a[0] << '\n';
		for (int _ = 0; _ < q; _++) {
			int l, r; cin >> l >> r;
			cout << a[0] << '\n';
		}
		return;
	}

	ll cur = 0;

	auto value = [&](const set<int> &ind) -> ll {
		ll ans = 0;
		for (int i: ind) {
			if (i < 0 or i >= n) continue;
			if (i == 0) {
				// Add only if mountain
				if (a[0] > a[1]) {
					ans += a[0];
				}
			} else if (i == n - 1) {
				// Add only if mountain
				if (a[i-1] < a[i]) {
					ans += a[i];
				}
			} else {
				// Add if mountain and subtract if valley
				if (a[i-1] < a[i] and a[i] > a[i+1]) {
					ans += a[i];
				} else if (a[i-1] > a[i] and a[i] < a[i+1]) {
					ans -= a[i];
				}
			}
		}
		return ans;
	};

	set<int> s;
	for (int i = 0; i < n; i++) s.insert(i);
	cur += value(s);
	cout << cur << '\n';

	for (int _ = 0; _ < q; _++) {
		int l, r; cin >> l >> r;
		l--; r--;
		s = set<int>({l-1, l, l+1, r-1, r, r+1});
		ll old = value(s);
		swap(a[l], a[r]);
		cur += value(s) - old;
		cout << cur << '\n';
	}
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
