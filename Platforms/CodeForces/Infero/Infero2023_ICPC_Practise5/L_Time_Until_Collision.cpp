#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, l; cin >> n >> l;
	vector<int> a(n + 2);
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = l;

	double xLow = 0, xHigh = l, x, t1 = 0, t2 = l, eps = 1e-7;
	while (abs(t1 - t2) > eps) {
		x = (xLow + xHigh) / 2;
		t1 = 0;
		for (int i = 1; i <= n + 1; i++) {
			if (a[i] < x) {
				t1 += double(a[i] - a[i - 1]) / i;
			} else {
				t1 += double(x - a[i - 1]) / i;
				break;
			}
		}
		t2 = 0;
		for (int i = n, s = 1; i >= 0; i--, s++) {
			if (x < a[i]) {
				t2 += double(a[i + 1] - a[i]) / s;
			} else {
				t2 += double(a[i + 1] - x) / s;
				break;
			}
		}

		if (t1 <= t2) {
			xLow = x;
		} else {
			xHigh = x;
		}
	}
	cout << t1;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	cout << fixed << setprecision(15);

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}

	return 0;
}
