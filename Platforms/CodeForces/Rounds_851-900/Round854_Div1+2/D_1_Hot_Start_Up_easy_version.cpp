#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, k; cin >> n >> k;
	vector<int> ps(n); for (auto &x: ps) cin >> x;

	vector<int> c(k), h(k);
	for (int &i: c) cin >> i;
	for (int &i: h) cin >> i;

	/**
	 * dp[i][j] := Time after having processed i tasks
	 *   j-th of which is currently has finished in CPU2
	 */
	vector<vector<int>> dp(n, vector<int> )

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
