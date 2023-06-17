#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int P = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	int ans = 0;
	for (int i = 0, j = 1; i < 10; i++, j *= 2) {
		int M = 0, m = 1;
		for (int &x: a) {
			M = max(M, x%2);
			m = min(m, x%2);
			x /= 2;
		}
		if (m == 0 and M == 1)
			ans += j;
	}

	cout << ans;
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

