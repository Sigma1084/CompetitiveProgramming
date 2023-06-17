#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, k; cin >> n >> k;
	vector<int> a(n); for (int &i: a) cin >> i;
	vector<int> t(n); for (int &i: t) cin >> i;

	vector<int> pref(n + 1), preft(n + 1);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + a[i];
		preft[i + 1] = preft[i] + (t[i] ? a[i] : 0);
	}

	// pref[i] := [0, i)

	int ans = preft.back();

	for (int l = 0; l + k <= n; l++) {
		ans = max(ans,
			preft[l] - preft[0]  // [0, l)
			+ pref[l + k] - pref[l]  // [l, l + k)
			+ preft[n] - preft[l + k]  // [l + k, n)
		);
	}

	cout << ans;

	return 0;
}
