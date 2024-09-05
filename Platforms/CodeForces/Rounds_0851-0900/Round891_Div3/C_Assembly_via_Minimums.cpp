#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a(n * (n - 1) / 2);
	for (auto &x: a) cin >> x;

	map<int, int> m;
	for (int x: a) m[x]++;

	vector<int> b(n);
	for (int i = n - 1; i > 0; i--) {
		auto [x, f] = *m.begin();
		b[i] = x;
		if (f == i) {
			m.erase(x);
		} else {
			m[x] -= i;
		}
	}

	b[0] = b[1];

	for (auto x: b) {
		cout << x << ' ';
	}
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
