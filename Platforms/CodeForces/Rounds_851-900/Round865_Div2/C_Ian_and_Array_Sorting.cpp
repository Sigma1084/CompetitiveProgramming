#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<ll> a(n); for (auto &x: a) cin >> x;

	// If n is odd, we can add or subtract indivisual elements independently
	if (n % 2 == 1) {
		cout << "YES";
		return;
	}

	// Any 2 interior points can be independently added
	for (int i = 1; i + 2 < n; i++) {
		a[n - 2 + (i%2)] -= a[0] - a[i];
		a[i] += a[0] - a[i];
	}

	if (a[n-1] >= a[n-2]) {
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
