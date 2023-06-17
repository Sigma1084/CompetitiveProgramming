#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;

	int r = 0, c = 0, cP = 1, l = 1;
	int a[n][n];
	int b[n*n];
	for (int i = 1, j = n*n, k = 1; k <= n*n; k++) {
		if (k&1) b[k-1] = i++;
		else b[k-1] = j--;
	}


	for (int r = 0, k = 0; r < n; r++) {
		if (r % 2 == 0) {
			for (int c = 0; c < n; c++) {
				a[r][c] = b[k++];
			}
		} else {
			for (int c = n-1; c >= 0; c--) {
				a[r][c] = b[k++];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
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
