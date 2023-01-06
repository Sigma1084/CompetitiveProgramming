#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int P = 1e9 + 7;

void solve() {
	int k; cin >> k;
	
	/**
	 * 
	 * Have a DAG from lesser vertex to greater vertex always
	 * Connect 1 to every other
	 * Connect 2 to 3, 4, ...
	 * Connect 3 to 4, 5, ...
	 * 
	 * 1, 3, 6, 10, 15
	 * 2, 3, 4, 5, 6
	 * 
	 * k = 1 => n = 2 totalPairs = 1 so ans = (2, 0)
	 * k = 2 => n = 4 totalPairs = 6 so ans = (4, 4)
	 * k = 3 => n = 3 totalPairs = 3 so ans = (3, 0)
	 * k = 4 => (k = 3 + k = 1) (3, 0) + (2, 0) = (5, 6)
	 * k = 5 => (k = 3 + k = 2) (3, 0) + (4, 4) = (7, 16)
	 * k = 6 => n = 4 totalPairs = 10 so ans = (4, 0)
	 */

	vector<int> triangularNumbers;
	triangularNumbers.push_back(1);  // triangularNumbers[i] needs i+2 vertices
	for (int i = 2; triangularNumbers.back() <= k; i++)
		triangularNumbers.push_back(triangularNumbers.back() + i);

	vector<int> dp(k+1, INT_MAX);
	dp[0] = 0;

	for (int i = 0; i < triangularNumbers.size(); i++)
		dp[triangularNumbers[i]] = i+2;

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < triangularNumbers.size() and triangularNumbers[j] <= i; j++) {
			dp[i] = min(dp[i], j+2 + dp[i-triangularNumbers[j]]);
		}
	}

	int n = dp[k];
	cout << n << ' ' << (ll) n * (n - 1) / 2 - k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i=1; i<=t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}

