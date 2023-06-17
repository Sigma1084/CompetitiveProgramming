#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;
	sort(all(a));

	vector<int> f(n, 0);
	for (int &i: a) f[i]++;

	ll pre = 0, suf = n, ans = 1;
	for (int i = 0; i < n; i++) {
		/**
		 * Say i ppl are going
		 * Number of ppl who will go happily = f[0] + f[1] + ... + f[i-1]
		 * Number of ppl staying back happily = f[i+1] + f[i+2] + ... + f[n-1]
		 * If we have someone in f[i] they will be sad however
		 */
		if (pre == i and f[i] == 0) ans++;
		pre += f[i];
	}

	cout << ans;
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
