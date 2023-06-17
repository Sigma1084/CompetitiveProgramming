#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	string s; cin >> s;

	vector<vector<int>> costs(26, {0});

	for (int i = 0; i < n; i++) {
		costs[s[i] - 'a'].push_back(i + 1);
	}

	int m; cin >> m;
	string t;
	int ans = 0;

	for (int _ = 0; _ < m; _++) {
		cin >> t;
		vector<int> f(26);
		for (const char &c: t) {
			f[c - 'a']++;
		}

		ans = 0;
		for (int i = 0; i < 26; i++) {
			ans = max(ans, costs[i][f[i]]);
		}

		cout << ans << '\n';
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
