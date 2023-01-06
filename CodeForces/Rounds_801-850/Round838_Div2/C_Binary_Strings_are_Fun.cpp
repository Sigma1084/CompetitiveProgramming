#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 998244353;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	ll ans = 1, cur = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i-1]) (cur *= 2) %= MOD;
		else cur = 1;
		(ans += cur) %= MOD;
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

