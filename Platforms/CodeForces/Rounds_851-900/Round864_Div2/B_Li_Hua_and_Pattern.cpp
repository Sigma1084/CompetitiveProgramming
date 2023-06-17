#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, k; cin >> n >> k;
	vector<vector<int>> a(n, vector<int>(n));
	for (auto &v: a) for (auto &x: v) cin >> x;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[n-1-i][n-1-j] != a[i][j]) ans++;
		}
	}
	ans /= 2;

	if (ans <= k and ((k - ans) % 2 == 0 or n % 2 == 1)) {
		cout << "YES";
	} else {
		cout << "NO";
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
