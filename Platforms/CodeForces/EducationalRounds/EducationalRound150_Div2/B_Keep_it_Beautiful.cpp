#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a(1); cin >> a[0];
	vector<int> ans = {1};

	int j = -1;
	for (int i = 1, x; i < n; i++) {
		cin >> x;
		if (j == -1) {
			if (x >= a.back()) {
				ans.push_back(1);
				a.push_back(x);
			} else if (x <= a.front()) {
				ans.push_back(1);
				a.push_back(x);
				j = 0;
			} else {
				ans.push_back(0);
			}
		} else if (x >= a.back() and x <= a.front()) {
			a.push_back(x);
			ans.push_back(1);
		} else {
			ans.push_back(0);
		}
	}
	for (int i: ans) cout << i;
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
