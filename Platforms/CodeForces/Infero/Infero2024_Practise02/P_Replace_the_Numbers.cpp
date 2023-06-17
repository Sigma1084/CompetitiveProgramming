#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int q; cin >> q;
	vector<array<int, 3>> queries;
	for (int i = 0, t, x, y; i < q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> x; y = 0;
		} else if (t == 2) {
			cin >> x >> y;
		}
		queries.push_back({t, x, y});
	}
	reverse(queries.begin(), queries.end());

	constexpr int N = 500'000;
	vector<int> pointsTo(N + 1);
	iota(pointsTo.begin(), pointsTo.end(), 0);

	vector<int> a;
	for (auto [t, x, y]: queries) {
		if (t == 1) {
			a.push_back(pointsTo[x]);
		} else if (t == 2) {
			pointsTo[x] = pointsTo[y];
		}
	}
	reverse(a.begin(), a.end());

	for (int i: a) cout << i << ' ';
	cout << endl;

	return 0;
}
