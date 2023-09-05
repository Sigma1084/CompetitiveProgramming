#include <bits/stdc++.h>
using namespace std;

constexpr int D = 24;
using BS = bitset<D>;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, nQ; cin >> n >> nQ;
	vector<BS> a(n);
	for (BS &x: a) {
		int _x; cin >> _x;
		x = _x;
	}

	vector<vector<int>> occs(D);

	for (int i = 0; i < n; i++) {
		for (int d = 0; d < D; d++) {
			if (a[i][d]) {
				occs[d].push_back(i);
			}
		}
	}

	/**
	 * dp[i][d] := Least index reachable from index i
	 *   such that dth digit is 1
	 */
	vector<vector<int>> dp(n, vector<int>(D, n));

	auto merge = [&dp](int i, int j) {
		for (int d = 0; d < D; d++) {
			dp[i][d] = min(dp[i][d], dp[j][d]);
		}
	};

	for (int i = n - 1; i >= 0; i--) {
		// Edit dp[i]
		for (int d = 0; d < D; d++) {
			if (a[i][d]) {
				dp[i][d] = i;
				auto it = upper_bound(occs[d].begin(), occs[d].end(), i);
				if (it != occs[d].end()) {
					merge(i, *it);
				}
			}
		}
	}

	for (int q = 0, i, j; q < nQ; q++) {
		cin >> i >> j;
		i--; j--;
		int ans = n;
		for (int d = 0; d < D; d++) {
			if (a[j][d]) {
				ans = min(ans, dp[i][d]);
			}
		}
		if (ans <= j) {
			cout << "Shi\n";
		} else {
			cout << "Fou\n";
		}
	}

	return 0;
}
