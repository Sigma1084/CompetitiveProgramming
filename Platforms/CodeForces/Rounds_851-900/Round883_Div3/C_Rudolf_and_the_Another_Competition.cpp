#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

using Score = pair<int, ll>;

void solve() {
	int n, m, lim; cin >> n >> m >> lim;
	vector<int> a(m);

	auto getScore = [&] () {
		for (int &i: a) cin >> i;
		sort(a.begin(), a.end());
		Score ans = {0, 0};
		ll tot = 0;
		for (int x: a) {
			if (tot + x > lim) break;
			tot += x;
			ans.first++;
			ans.second -= tot;
		}
		return ans;
	};

	Score score1 = getScore();
	int ans = 1;
	for (int i = 1; i < n; i++) {
		Score s = getScore();
		if (s > score1) ans++;
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
