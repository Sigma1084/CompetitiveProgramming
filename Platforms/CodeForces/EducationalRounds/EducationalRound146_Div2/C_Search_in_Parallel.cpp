#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, s1, s2; cin >> n >> s1 >> s2;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.rbegin(), a.rend());

	vector<int> b1, b2;
	for (auto [t, i]: a) {
		if (s1 * (b1.size() + 1) <= s2 * (b2.size() + 1)) {
			b1.push_back(i);
		} else {
			b2.push_back(i);
		}
	}

	cout << b1.size() << ' ';
	for (int i: b1) cout << i << ' ';
	cout << '\n';
	cout << b2.size() << ' ';
	for (int i: b2) cout << i << ' ';
	cout << '\n';
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
