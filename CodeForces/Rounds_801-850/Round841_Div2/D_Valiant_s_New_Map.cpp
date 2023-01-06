#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int P = 1e9 + 7;

void solve() {
	int n, m; cin >> n >> m;

	int a[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	int d[n][m][2];
	for (int i = 0; i < n; i++) {
		array<int, 2> x[m];
		for (int j = 0; j < m; j++)
			x[j] = { a[i][j], j};
		sort(x, x+m);

		for (int j = 0; j < m; j++) {
			// Find before and after using binary search
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}

