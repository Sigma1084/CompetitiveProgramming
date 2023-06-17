#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, m, K = -1; cin >> n >> m;

	for (int i = min(m, n); i; i /= 2)
		K++;

	int st[K+1][n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> st[0][i][j];

	for (int shift = 1, k = 1; k <= K; k++, shift *= 2) {
		for (int i = 0; i + 2*shift <= n; i++) {
			for (int j = 0; j + 2*shift <= m; j++) {
				st[k][i][j] = min( min(st[k-1][i][j], st[k-1][i+shift][j]),
					min(st[k-1][i][j+shift], st[k-1][i+shift][j+shift]) );
			}
		}
	}

	int k, l;
	for (k = K, l = 1 << K; k; k--, l /= 2) {
		for (int i = 0; i + l <= n; i++)
			for (int j = 0; j + l <= m; j++) {
				if (st[k][i][j] >= l)
					goto out;
			}
	}
	out:

	// A length l is always possible now and a length 2l is not possible

	int a = l + 1, b = min(min(n, m), 2*l - 1);

	while (a <= b) {
		int mid = (a + b) / 2;
		bool ok = false;
		for (int i = 0; i + mid <= n; i++) {
			for (int j = 0; j + mid <= m; j++) {
				int diff = mid - l;
				int val = min(min(st[k][i][j], st[k][i+diff][j]), 
					min(st[k][i][j+diff], st[k][i+diff][j+diff]) );
				if (val >= mid) {
					ok = true;
					goto out2;
				}
			}
		}
		out2:
		if (ok) a = mid + 1;
		else b = mid - 1;
	}

	cout << b;
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
