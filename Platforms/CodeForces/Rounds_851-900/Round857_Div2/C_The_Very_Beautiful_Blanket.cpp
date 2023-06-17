#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


constexpr int N = 200 + 2;
vector<vector<ll>> ans(N, vector<ll>(N));


void solve() {
	int n, m; cin >> n >> m;

	// for (int i = 0; i+2 < n; i++) {
	// 	for (int j = 0; j+2 < m; j++) {
	// 		cerr << (ans[i][j] ^ ans[i+1][j] ^ ans[i][j+1] ^ ans[i+1][j+1]) << ' ';
	// 	}
	// 	cerr << '\n';
	// }

	cout << n * m << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;


	ll cnt = 0;
	for (int i = 0; i+2 < N; i += 2) {
		cnt = i << 10;
		for (int j = 0; j+2 < N; j += 2) {
			ans[i][j] = cnt++;
			ans[i+1][j] = cnt++;
			ans[i+1][j+1] = cnt++;
			ans[i][j+1] = cnt++;
		}
	}

	for (int i = 1; i <= t; i++) {
		solve();  // cout << '\n';
	}
	return 0;
}
