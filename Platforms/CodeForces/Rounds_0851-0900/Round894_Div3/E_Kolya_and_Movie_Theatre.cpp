#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

/**
 * For every i, we need to keep track of the 
 * maximum m terms seen so far.
 */
void solve() {
	int n, m, d; cin >> n >> m >> d;
	vector<int> a(n); for (auto &x: a) cin >> x;

	priority_queue<int, vector<int>, greater<>> pq;
	ll ans = 0, cur = 0;

	for (int i = 0; i < n; i++) {
		// Cost for current i = - d * (i + 1)
		if (a[i] > 0) {
			pq.push(a[i]);
			cur += a[i];
		}
		if (pq.size() > m) {
			cur -= pq.top();
			pq.pop();
		}
		ans = max(ans, cur - 1LL * d * (i + 1));
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
