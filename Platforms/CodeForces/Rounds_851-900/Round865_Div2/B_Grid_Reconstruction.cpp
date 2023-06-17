#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	
	vector<vector<int>> a(2, vector<int>(n));
	a[0][0] = 2 * n - 1;
	a[1][n-1] = 2 * n;

	for (int i = 1, j = 1; j+1 < n; i ^= 1, j++) {
		a[i][j] = a[i^1][j-1] - 1;
	}

	for (int c = 1; c < n; c += 2) {
		a[0][c] = c;
	}

	for (int c = 0; c < n; c += 2) {
		a[1][c] = c + 2;
	}

	for (const auto &v: a) {
		for (int x: v) cout << x << ' ';
		cout << '\n';
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
