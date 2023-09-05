#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	int g = 0;
	for (int i = 0; i < n; i++) {
		g = gcd(g, a[i]);
	}

	if (g != a[0]) {
		cout << -1;
	} else if (n == 1) {
		cout << 1 << '\n' << a[0];
	} else {
		cout << 2 * (n - 1) << '\n';
		for (int i = 1; i < n; i++) {
			cout << g << ' ' << a[i] << ' ';
		}
	}

	return 0;
}
