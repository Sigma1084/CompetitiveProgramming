#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;
	
	for (auto &i: a) if (!i) i = -1;
	array<int, 3> ans = { 0, 0, -1 };
	int l = 0, curSum = a[0];

	for (int i = 1; i < n; i++) {
		if (curSum + a[i] >= 0) {
			curSum += a[i];
		} else {
			curSum = 0; l = i;
		}
		ans = max(ans, { curSum, l, i+1 } );
	}

	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
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
