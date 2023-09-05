#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);

	int n; cin >> n;
	vector<int> a(n);
	for (int &x: a) { cin >> x; x %= 7; }

	vector<int> pref(n); pref[0] = a[0];
	for (int i = 1; i < n; i++) {
		pref[i] = (pref[i - 1] + a[i]) % 7;
	}

	vector<int> first(7, n), last(7, -1);
	for (int i = 0; i < n; i++) {
		first[pref[i]] = min(first[pref[i]], i);
		last[pref[i]] = max(last[pref[i]], i);
	}

	int ans = 0;
	for (int i = 0; i < 7; i++) {
		ans = max(ans, last[i] - first[i]);
	}
	cout << ans << endl;

	return 0;
}
