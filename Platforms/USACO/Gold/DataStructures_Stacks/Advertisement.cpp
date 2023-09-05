#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	/**
	 * If I want to include the tower a[i], how do I construct the sequence?
	 * 
	 * If a[i] > a[i-1], then we need to start the sequence of a[i] from i
	 * 
	 * If a[i] <= a[i-1], then we can start sequence of a[i]
	 * from where we started the sequence of a[i-1]
	 * Also, the sequence that involves a[i-1] must be terminated here.
	 */

	stack<pair<int, int>> st;  // [start pos, val]
	int64_t ans = 0;

	for (int i = 0, j, x; i < n; i++) {
		j = i;
		while (!st.empty() and st.top().second >= a[i]) {
			// Eliminating the values >= a[i]
			j = st.top().first; x = st.top().second;
			ans = max(ans, int64_t(i - j) * x);
			st.pop();
		}
		// We can start counting a[i]'s from position j,
		// where we started the sequences with values >= a[i]
		st.emplace(j, a[i]);
	}

	// Terminating the remaining sequences at the end
	while (not st.empty()) {
		auto [j, x] = st.top();
		ans = max(ans, int64_t(n - j) * x);
		st.pop();
	}

	cout << ans;

	return 0;
}
