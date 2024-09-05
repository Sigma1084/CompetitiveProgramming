#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto &x: a) { cin >> x; x--; }

	vector<multiset<int>> s(k);
	vector<int> prev(k, -1);

	for (int i = 0; i < n; i++) {
		// a[i] is the color
		// prev[a[i]] is the prev occurace of the color
		s[a[i]].insert(i - prev[a[i]]);
		prev[a[i]] = i;
	}

	int ans = n + 1;
	for (int c = 0; c < k; c++) {
		s[c].insert(n - prev[c]);
		int last = *s[c].rbegin();
		s[c].erase(s[c].find(last));
		s[c].insert(last / 2);
		s[c].insert((last + 1) / 2);
		ans = min(ans, *s[c].rbegin() - 1);
	}

	ans = max(ans, 0);
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
