#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


/**
 * Notice if we have ranges [l1, r1] and [l2, r2] with l1 < l2 and r1 < r2,
 * that is, neither range is contained in the other, then
 * these cows will never collide.
 * 
 * We need to find the maximum number of ranges continuously contained
 * l1 <= l2 <= ... <= lk  <=  rk <= ... <= r1
 * 
 * Sort based on end-time DESC
 * 
 * Finding l1 <= l2 implies r1 >= r2 due to sorting
 * l1 <= l2 <= l3 <= ... <= lk implies r1 >= r2 >= r3 >= ... >= rk
 * 
 * To ensure l1 <= l2 if r2 = r1, secondary sort based on start-time ASC
 * Now, we need to find a Largest Non-Decreasing Subsequence of start-times
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);

	int n, t; cin >> n >> t;
	vector<pair<int, ll>> ranges(n);
	for (auto &[start, end]: ranges) {
		ll speed; cin >> start >> speed;
		end = start + speed * t;
	}

	sort(ranges.begin(), ranges.end(), [](auto a, auto b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second > b.second;
	});

	// Find Largest Non-Decreasing Sequence of start-times
	vector<int> lnds;
	for (auto [x, _]: ranges) {
		if (lnds.empty() or x >= lnds.back()) lnds.push_back(x);
		else *lower_bound(lnds.begin(), lnds.end(), x + 1) = x;
	}

	cout << lnds.size() << endl;

	return 0;
}
