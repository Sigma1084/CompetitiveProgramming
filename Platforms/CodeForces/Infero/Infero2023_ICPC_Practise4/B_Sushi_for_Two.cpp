#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	vector<int> b; int cur = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i-1]) {
			cur++;
		} else {
			b.push_back(cur);
			cur = 1;
		}
	}
	b.push_back(cur);

	int ans = 0;
	for (int i = 1; i < b.size(); i++) {
		ans = max(ans, min(b[i-1], b[i]));
	}

	cout << 2 * ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
