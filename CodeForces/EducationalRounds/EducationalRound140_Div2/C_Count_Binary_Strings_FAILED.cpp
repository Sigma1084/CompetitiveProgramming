#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int MOD = 998244353;

void solve() {
	int n; cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++) {
		if (a[i][i] == 2) {
			cout << 0;
			return;
		}
		a[i][i] = 0;
	}

	// Simplify the ones and eliminate them
	vector<pair<int, int>> ones;

	auto processOnes = [&a] (int l, int r) -> bool {
		// We need to make sure everything under l, r has only 0s and 1s
		for (int i = l; i <= r; i++) {
			for (int j = i+1; j <= r; j++) {
				if (a[i][j] == 2) {
					return false;
				} else {
					a[i][j] = 0;
				}
			}
		}
		return true;
	};
	
	for (int d = n-1; d > 0; d--) {
		for (int i = 0; i+d < n; i++) {
			if (a[i][i+d] != 1) continue;
			// Now, we found a range [i, ... i+d] same
			// Verify and return
			if (not processOnes(i, i+d)) {
				cout << 0;
				return;
			}
			ones.emplace_back(i, i+d);
		}
	}

	// Now, we have a disjoint set of ones
	// Verify these ones
	vector<pair<int, int>> onesDisjoint;

	int l = -1, r = -1;
	for (int i = 0; i < ones.size(); i++) {
		if (l == -1) {
			l = ones[i].first;
			r = ones[i].second;
		} else {
			if (ones[i].first <= r and i+1 < ones.size()) {
				// Overlap
				r = ones[i].second;
			} else {
				// No overlap
				// Process and move forward
				if (not processOnes(l, r)) {
					cout << 0;
					return;
				} else {
					onesDisjoint.push_back({l, r});
					a[l][r] = 1;
				}
				l = ones[i].first;
				r = ones[i].second;
			}
		}

		if (i+1 == ones.size())
			if (not processOnes(l, r)) {
				cout << 0;
				return;
			} else {
				onesDisjoint.push_back({l, r});
				a[l][r] = 1;
			}
	}

	// We now have a disjoint set of ones where we can reduce our problem to
	for (int i = 0; i < n; ) {
		for (int j = i+1; j < n; j++) {
			if (a[i][j] == )
		}
	}

	ll ans = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

