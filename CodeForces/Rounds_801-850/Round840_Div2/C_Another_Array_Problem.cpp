#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int P = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<ll> a(n); for (auto &x: a) cin >> x;
	if (n > 3) {
		cout << *max_element(all(a)) * n;
	} else if (n == 2) {
		cout << max(a[0] + a[1], 2 * abs(a[0] - a[1]));
	} else {
		assert(n == 3);

		ll ans = a[0] + a[1] + a[2];
		ans = max(ans, 3 * a[0]);
		ans = max(ans, 3 * a[2]);

		auto b = a;
		b[0] = b[1] = abs(b[1] - b[0]);
		ans = max(ans, b[0] + b[1] + b[2]);
		b[2] = b[1] = abs(b[1] - b[2]);
		ans = max(ans, b[0] + b[1] + b[2]);
		ans = max(ans, max(3 * b[0], 3 * b[2]));

		b = a;
		b[2] = b[1] = abs(b[1] - b[2]);
		ans = max(ans, b[0] + b[1] + b[2]);
		b[0] = b[1] = abs(b[1] - b[0]);
		ans = max(ans, b[0] + b[1] + b[2]);
		ans = max(ans, max(3 * b[0], 3 * b[2]));

		cout << ans;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}

