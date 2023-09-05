#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	int i = min_element(a.begin(), a.end()) - a.begin();
	int j = max_element(a.begin(), a.end()) - a.begin();

	if (i > j) {
		// std::tie(i, j) = make_pair(j, i);
		swap(i, j);
	}

	// i < j
	// i and then j OR j and then i
	int ans1 = i + 1 + min(n - j, j - i);
	int ans2 = n - j + min(i + 1, j - i);

	cout << min(ans1, ans2);
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
