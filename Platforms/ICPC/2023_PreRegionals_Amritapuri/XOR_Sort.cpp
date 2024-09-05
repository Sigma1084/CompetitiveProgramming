#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	vector<int> ar(n); for (auto &x: ar) cin >> x;

	vector<pair<int, int>> ans;
	auto swapInd = [&] (int i, int j) {
		swap(ar[i], ar[j]);
		ans.emplace_back(i, j);
		ans.emplace_back(j, i);
		ans.emplace_back(i, j);
	};

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++)
		a[i] = {ar[i], i};
	sort(all(a));

	vector<int> posOfOgInA(n);
	for (int i = 0; i < n; i++)
		posOfOgInA[a[i].second] = i;

	for (int i = n-1, j; i >= 0; i--) {
		auto [ele, ogIndLast] = a[i];  // (9, 5)
		if (ogIndLast == i) continue;
		j = posOfOgInA[i];  // 2
		auto [ele2, ogIndFirst] = a[j];  // (2, 2)
		swapInd(ogIndFirst, ogIndLast);
		a[i].second = ogIndFirst;
		a[j].second = ogIndLast;
		posOfOgInA[ogIndLast] = j;
	}

	cout << ans.size() << '\n';
	for (auto [i, j]: ans) {
		cout << i+1 << ' ' << j+1 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve();  // cout << '\n';
	}
	return 0;
}
