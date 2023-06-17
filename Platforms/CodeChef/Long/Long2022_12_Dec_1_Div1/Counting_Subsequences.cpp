#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

/**
 * Thought Process for
 * n = 9
 * 5 7 9 3 4 1 8 6 4
 * dp(2) = 1
 * dp(4) = 1
 * dp(8) = 1
 * dp(3) = 1 + dp(1) + dp(2) = 3
 * dp(5) = 1 + dp(1) + dp(4) = 3
 * dp(6) = 1 + dp(2) = 2
 * dp(7) = 1 + dp(1) + dp(2) + dp(3) + dp(4) + dp(6) = 9
 * dp(9) = 1 + dp(1) + dp(8) = 3
 * ans = 4 + 3 + 3 + 2 + 9 + 3 = 24
 */

int n;
vector<ll> dp;

void solve() {
    cin >> n;
    vector<int> a(n); for (int &i: a) cin >> i;
    reverse(a.begin(), a.end());

    dp.clear(); dp.resize(n+1); /* Subsequences starting from i */
    for (int &m: a) {
        /* Iterate through all the submasks of mask m */
        for (int s = m; s; s = (s-1)&m)
            dp[m] += dp[s];
        dp[m]++; dp[m] %= MOD;
    }

    cout << accumulate(dp.begin(), dp.end(), 0LL) % MOD;
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

