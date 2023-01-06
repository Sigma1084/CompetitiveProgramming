#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int P = 1e9 + 7;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n); for (int &i: a) cin >> i;

	sort(all(a));
	ll ans = 0;
	for (int i = 0, j = n-1; i <= j;) {
		if (i == j) {
			ans += a[i++] + 1;
		} else if (a[i] + a[j] > m) {
			ans += a[j--] + 1;
		} else {
			/**
			 * We have a[i] a[i+1] ... a[j-1] a[j]
			 * Download j and then download i while watching j
			 * By the time i is done downloading, watching j is complete
			 */
			ans += a[i++] + a[j--];
			if (i > j) ans += 1; // Explicitly watch the last video
		}
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i=1; i<=t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}

