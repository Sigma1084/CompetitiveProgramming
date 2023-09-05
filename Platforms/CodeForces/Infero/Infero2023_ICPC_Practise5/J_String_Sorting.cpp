#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<int> c(n);
	for (int &x: c) cin >> x;
	vector<string> s(n);
	for (string &x: s) cin >> x;

	vector<string> r = s;
	for (string &x: r) reverse(x.begin(), x.end());

	vector<ll> dpTop(n, 1e15);
	vector<ll> dpFlip(n, 1e15);
	dpTop[0] = 0;
	dpFlip[0] = c[0];

	for (int i = 1; i < n; i++) {
		if (s[i] >= s[i - 1]) dpTop[i] = min(dpTop[i], dpTop[i - 1]);
		if (s[i] >= r[i - 1]) dpTop[i] = min(dpTop[i], dpFlip[i - 1]);
		if (r[i] >= s[i - 1]) dpFlip[i] = min(dpFlip[i], dpTop[i - 1] + c[i]);
		if (r[i] >= r[i - 1]) dpFlip[i] = min(dpFlip[i], dpFlip[i - 1] + c[i]);
	}

	ll ans = min(dpTop.back(), dpFlip.back());
	if (ans > 1e14) ans = -1;

	cout << ans;

	return 0;
}
