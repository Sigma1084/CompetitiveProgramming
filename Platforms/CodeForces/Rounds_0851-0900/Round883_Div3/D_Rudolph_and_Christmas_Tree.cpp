#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, d, h;
	cin >> n >> d >> h;
	vector<int> y(n);
	for (int &x: y) cin >> x;

	sort(y.begin(), y.end());
	y.push_back(y.back() + h);

	for (int i: y) cerr << i << ' ';
	cerr << '\n';

	double d2, ans = 0;
	for (int i = 0, _h; i < n; i++) {
		_h = h - min(h, y[i + 1] - y[i]);
		d2 = double(d) * _h / h;
		ans += (d + d2) / 2 * (h - _h);
	}

	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;
	cout << fixed << setprecision(12);

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}

	return 0;
}
