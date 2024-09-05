#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] <= s[ans]) {
			ans = i;
		}
	}

	cout << s[ans] + s.substr(0, ans) + s.substr(ans + 1);
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
