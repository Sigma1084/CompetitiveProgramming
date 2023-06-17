#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	int a[n][n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	ll ans = 0;
	
	for (int r = 0; r < n; r++) {
		ll cur = 0;
		for (int i = 0; i+r < n; i++) {
			cur += a[i+r][i];
		}
		ans = max(ans, cur);
	}

	for (int c = 0; c < n; c++) {
		ll cur = 0;
		for (int j = 0; j+c < n; j++) {
			cur += a[j][j+c];
		}
		ans = max(ans, cur);
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ":" << ' ';
		solve(); cout << '\n';
	}
	return 0;
}
