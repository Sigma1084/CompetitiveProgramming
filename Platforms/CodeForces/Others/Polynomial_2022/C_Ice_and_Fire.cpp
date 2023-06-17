#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int ans = 1; cout << ans << ' ';
	for (int i = 1; i < n-1; i++) {
		if (s[i] != s[i-1]) {
			ans = i+1;
		}
		cout << ans <<  ' ';
	}
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

