#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

/**
 * dp[i][mask] := Max Strength if we choose
 * from the first i people (1-indexing)
 * and allot the positions given by the mask
 */
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, p, k; cin >> n >> p >> k;
	vector<int> a(n);
	for (int &x: a) cin >> x;

	vector<vector<int>> s(n, vector<int>(p));
	for (auto &si: s) for (auto &sij: si) cin >> sij;

	vector<int> o(n);
	iota(o.begin(), o.end(), 0);
	sort(o.begin(), o.end(), 
		[&a](int i, int j) { return a[i] > a[j]; });

	// We now have an ordering given by o
	// We always have a[o[i]] > a[o[j]] whenever i < j
	vector<ll> dp(1 << p);

	for (int i = 0, maskSize; i < n; i++) {
		// We need to use a[o[i]] and s[o[i]]
		// i := Number of people seen so far

		// We iterate from top since 
		// dp[mask] depends on dpOld[mask - <something>]
		// But dpOld[mask - <x>] is dp[mask - <x>]
		for (int mask = (1 << p) - 1; mask >= 0; mask--) {
			maskSize = bitset<8>(mask).count();

			// If there are not enough audience, add o[i]
			if (i - maskSize < k and maskSize <= i)
				dp[mask] += a[o[i]];

			for (int j = 0; j < p; j++) {
				if (!(mask & (1 << j))) continue;
				// We can select person o[i] for the j-th position
				dp[mask] = max(dp[mask], dp[mask - (1 << j)] + s[o[i]][j]);
			}
		}
	}

	cout << dp[(1 << p) - 1] << endl;
	return 0;
}
