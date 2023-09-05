#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

	map<char, int> m = { {'H', 0}, {'P', 1}, {'S', 2} };

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		a[i] = m[c];
	}

	vector<array<int, 3>> pref(n + 1);
	pref[0] = {0, 0, 0};

	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i];
		pref[i + 1][a[i]]++;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int maxLeft = max({ pref[i][0], pref[i][1], pref[i][2] });
		int maxRight = max({pref[n][0] - pref[i][0], pref[n][1] - pref[i][1],
			pref[n][2] - pref[i][2]});
		ans = max(ans, maxLeft + maxRight);
	}

	cout << ans;

	return 0;
}
