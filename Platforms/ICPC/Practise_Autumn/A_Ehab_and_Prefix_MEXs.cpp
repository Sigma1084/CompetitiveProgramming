#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;

	/**
	 * Observations: 
	 * 1. a[i] <= i + 1
	 * 2. a[i] != a[i - 1]  ==>  ans[i] = a[i - 1]
	 */

	set<int> s;
	for (int i = 0; i <= n; i++) s.insert(i);
	vector<int> ans(n, -1);

	for (int i = 0; i < n; i++) {
		if (a[i] > i + 1) {
			cout << -1;
			return 0;
		} else if (i and a[i] != a[i - 1]) {
			ans[i] = a[i - 1];
			s.erase(ans[i]);
		}
	}

	s.erase(a.back());
	for (int i = 0; i < n; i++) {
		if (ans[i] == -1) {
			ans[i] = *s.begin();
			s.erase(s.begin());
		}
	}

	for (int x: ans) {
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}
