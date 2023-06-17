#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	map<ll, pair<int, int>> points;
	for (ll i = 0, l, r; i < n; i++) {
		cin >> l >> r;
		points[l].first++;
		points[r].second++;
	}

	vector<ll> ans(n + 1);
	ll t0 = 0, cur = 0;
	for (auto [t, p]: points) {
		ans[cur] += t - t0 - 1;
		cur += p.first;
		ans[cur]++;
		cur -= p.second;
		t0 = t;
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;

	return 0;
}
