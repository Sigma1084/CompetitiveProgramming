#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

double help(double x, double y, double s1, double s2) {
	assert(x <= y);
	return (s1 * x + s2 * y) / (s1 + s2);
}

void solve() {
	int n, l; cin >> n >> l;
	vector<int> a(n + 2);
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = l;
	sort(a.begin(), a.end());

	vector<double> t1(n + 2), t2(n + 2);
	vector<int> s1(n + 2), s2(n + 2);

	s1[0] = 1;
	for (int i = 1; i <= n + 1; i++) {
		t1[i] = t1[i - 1] + double(a[i] - a[i - 1]) / s1[i - 1];
		s1[i] = s1[i - 1] + 1;
	}

	s2[n + 1] = 1;
	for (int i = n; i >= 0; i--) {
		t2[i] = t2[i + 1] + double(a[i + 1] - a[i]) / s2[i + 1];
		s2[i] = s2[i + 1] + 1;
	}

	int k = 0;
	while (k + 1 < n + 2 and t1[k + 1] < t2[k + 1]) k++;

	if (t1[k] <= t2[k + 1]) {
		double x = a[k] + s1[k] * (t2[k + 1] - t1[k]);
		double col = help(x, a[k + 1], s1[k], s2[k + 1]);
		cout << t2[k + 1] + (col - x) / s1[k];
	} else {
		double y = a[k + 1] - s2[k + 1] * (t1[k] - t2[k + 1]);
		double col = help(a[k], y, s1[k], s2[k + 1]);
		cout << t1[k] + (y - col) / s2[k + 1];
	}

	for (int i: a) cerr << double(i) << ' '; cerr << '\n';
	for (auto i: t1) cerr << i << ' '; cerr << '\n';
	for (auto i: t2) cerr << i << ' '; cerr << '\n';
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	cout << fixed << setprecision(15);
	cerr << fixed << setprecision(5);

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}

	return 0;
}
