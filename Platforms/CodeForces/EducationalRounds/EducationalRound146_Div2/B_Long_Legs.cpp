#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int a, b; cin >> a >> b;
	if (a > b) swap(a, b);  // Ensure a <= b

	int ans = 2e9;

	// Law of central tendency
	for (int k = 1; k <= 3 * sqrt(b); k++) {
		ans = min(ans, k - 1 + (int)ceil(1.0 * b / k) + (int)ceil(1.0 * a / k));
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
