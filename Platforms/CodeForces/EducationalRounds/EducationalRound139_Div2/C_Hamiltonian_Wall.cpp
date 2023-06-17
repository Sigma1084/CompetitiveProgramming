#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
    string s[2]; cin >> s[0] >> s[1];

    vector<vector<int>> dp(2, vector<int>(n));
    if (s[0][0] == 'B') dp[0][0] = true;
    if (s[1][0] == 'B') dp[1][0] = true;

    for (int i = 1; i < n; i++) {
        if (s[0][i] == 'B' and s[1][i] == 'B') {
            // Both are black case
            dp[0][i] = dp[1][i-1];
            dp[1][i] = dp[0][i-1];
        } else if (s[0][i] == 'B') {
            // Top is black
            dp[0][i] = dp[0][i-1];
        } else if (s[1][i] == 'B') {
            // Bottom is black
            dp[1][i] = dp[1][i-1];
        } else {
            
        }
    }

    // for (int i = 0; i < n; i++)
    //     cout << dp[0][i] << ' ';
    // cout << '\n';
    // for (int i = 0; i < n; i++)
    //     cout << dp[1][i] << ' ';
    // cout << '\n';

    if (dp[0][n-1] or dp[1][n-1])
        cout << "YES";
    else
        cout << "NO";
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

