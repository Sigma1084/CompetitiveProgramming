#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int &i: a) cin >> i;

	set<ll> all;
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		cur += a[i];
		all.insert(cur);
	}

	int ans = 0;
	for (auto s: all) {
		ans += all.count(s + x);
	}

	return 0;
}
