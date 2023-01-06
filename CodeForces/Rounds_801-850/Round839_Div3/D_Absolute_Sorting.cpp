#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	int m = 0, M = 1e9;
	for (int i = 1; i < n; i++) {
		if (a[i-1] < a[i]) {
			M = min(M, a[i-1] + (a[i] - a[i-1]) / 2);
		} else if (a[i-1] > a[i]) {
			m = max(m, a[i] + (a[i-1] - a[i] + 1) / 2);
		}
	}

	if (m <= M) {
		cout << m;
	} else {
		cout << -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

