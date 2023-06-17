#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	char c = s[0]; int l = 1;
	vector<int> maxF(26);
	int ans = 0;
	maxF[c-'a'] = 1;

	for (int i = 1; i < n; i++) {
		if (s[i] == c) l++;
		else c = s[i], l = 1;
		ans = max(ans, l-1);  // Accounting for doubles
		if (maxF[c-'a'] == l) ans = max(ans, l);
		maxF[c-'a'] = max(maxF[c-'a'], l);
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

