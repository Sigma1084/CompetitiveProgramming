#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a, b;
	for (int i = 0, x, y; i < 2 * n; i++) {
		cin >> x >> y;
		if (x) {
			a.push_back(abs(x));
		} else {
			b.push_back(abs(y));
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	double ans = 0;
	for (int i = 0; i < n; i++) {
		ans += sqrt(1.0 * a[i] * a[i] + 1.0 * b[i] * b[i]);
	}

	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	cout << fixed << setprecision(13);

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}

	return 0;
}
