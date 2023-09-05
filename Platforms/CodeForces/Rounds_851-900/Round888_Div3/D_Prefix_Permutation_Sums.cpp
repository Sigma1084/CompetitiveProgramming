#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<ll> p(n - 1); for (auto &x: p) cin >> x;
	vector<bool> present(n + 1);

	ll x, rem = -1;
	for (int i = 0; i + 1 < n; i++) {
		if (i) {
			x = p[i] - p[i - 1];
		} else {
			x = p[0];
		}

		assert(x >= 0);

		if (x <= n and !present[x]) {
			present[x] = true;
		} else if (rem == -1) {
			rem = x;
		} else {
			cout << "NO";
			return;
		}
	}

	if (rem == -1) {
		cout << "YES";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (present[i]) continue;
		rem -= i;
	}

	if (!rem) {
		cout << "YES";
	} else {
		cout << "NO";
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
