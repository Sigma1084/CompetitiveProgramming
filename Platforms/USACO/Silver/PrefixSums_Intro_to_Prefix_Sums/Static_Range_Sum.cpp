#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int &i: a) cin >> i;

	vector<ll> pref(n);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + a[i];
	}

	for (int _ = 0, l, r; _ < q; _++) {
		cin >> l >> r;
		cout << pref[r] - pref[l] << '\n';
	}

	return 0;
}
