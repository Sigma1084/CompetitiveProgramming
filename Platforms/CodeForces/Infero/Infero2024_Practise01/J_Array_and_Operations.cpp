#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n); for (auto &x: a) { cin >> x; x = -x; }
	multiset<int> ms(a.begin(), a.end());

	map<int, int> f;
	for (int i: a) f[i]++;

	for (auto [x, c]: f) {
		if (c)
	}

	int score = 0;
	while (k--) {
		if (*ms.begin() == *ms.rbegin()) {
			score -= *ms.begin();
			ms.erase(ms.begin());
			ms.erase(--ms.end());
		} else {
			ms.erase(ms.lower_bound(*ms.begin() + 1));
			ms.erase(ms.begin());
		}
		for (auto x: ms) cerr << x << ' '; cerr << '\n';
	}

	while (not ms.empty()) {
		score -= *ms.begin();
		ms.erase(ms.begin());
	}

	cout << score;
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
