#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n); for (auto &x: a) cin >> x;

	/**
	 * In any case, we will certainly end up in a situation where
	 * there are n - (m - 1) consecutive elements in the array
	 * Let us call this segment b[i] where 0 <= i < n - (m - 1)
	 */

	vector<int> b(n - (m - 1));
	for (int i = 0; i + m - 1 < n; i++) {
		b[i] = max(a[i], a[i + n - m]);
	}

	/**
	 * We assume k <= m - 1 w.l.o.g
	 * 
	 * The people after us are useless
	 * Suppose we control x people 0 <= x <= k
	 * 
	 * Then, we have y = (m - 1 - x) who we can not control
	 * Hence, we get an expression
	 * 
	 * max_{0 <= x <= k} min_{0 <= y <= m - 1 - x} b[x + y]
	 * max_{0 <= x <= k} min_{x <= y <= m - 1}
	 */
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
