#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	string s; cin >> s;

	map<int, int> bef, aft;
	for (char c: s) {
		bef[c]++;
	}

	int ans = bef.size() + aft.size();
	for (char c: s) {
		bef[c]--;
		aft[c]++;
		if (bef[c] == 0) bef.erase(c);
		ans = max(ans, static_cast<int>(bef.size() + aft.size()));
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
