#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

/**
 * Follows https://usaco.guide/problems/lmio-2019triusis/solution
 * 
 * We count the number of poles we don't change
 * Suppose the poles  i1, i2, ..., ik  don't change
 * Condition 1. a[i_j] <= M * i_j
 * Condition 2. a[i_{j+1}] <= a[i_j] + M * (i_{j+1} - i_j)
 * 
 * Hence, we have a[i_{j+1}] - M * i_{j+1} <= a[i_j] - M * i_j
 * or M * i_{j+1} - a[i_{j+1}] <= M * i_j - a[i_j]
 * 
 * Now, if b[i] = M * i - a[i], 
 * we can find the largest non-decreasing sequence of b[i]
 * where the the indices satisfy condition 1 (b[i] >= 0)
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int &x: a) cin >> x;

	vector<ll> lis;  // Largest Non-Decreasing Sequence of b[i]
	for (ll i = 0, x; i < n; i++) {
		x = 1LL * m * (i + 1) - a[i];  // b[i]
		if (x < 0) continue;
		if (lis.empty() or x >= lis.back()) lis.push_back(x);
		else *lower_bound(lis.begin(), lis.end(), x + 1) = x;
	}

	cout << n - lis.size() << endl;
}
