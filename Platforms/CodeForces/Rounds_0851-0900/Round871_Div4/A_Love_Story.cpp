#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

string cf = "codeforces";

void solve() {
	string s; cin >> s;
	int ans = 0;
	for (int i = 0; i < 10; i++)
		if (s[i] != cf[i]) ans++;
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
