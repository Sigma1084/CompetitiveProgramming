#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;
	sort(a.begin(), a.end());

	for (int i = 0; i + 1 < n; i++) {
		if (a[i + 1] - a[i] > 1) {
			cout << "NO";
			return;
		}
	}

	cout << "YES";
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
