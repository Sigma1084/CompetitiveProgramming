#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);

	int n, q; cin >> n >> q;
	vector<array<int, 3>> pref(n + 1);
	pref[0] = {0, 0, 0};

	for (int i = 0, x; i < n; i++) {
		cin >> x; x--;
		pref[i + 1] = pref[i];
		pref[i + 1][x]++;
	}

	for (int t = 0, l, r; t < q; t++) {
		cin >> l >> r; l--;
		for (int i = 0; i < 3; i++) {
			cout << pref[r][i] - pref[l][i];
			if (i + 1 < 3) cout << ' ';
		}
		if (t + 1 < q) cout << '\n';
	}

	return 0;
}
