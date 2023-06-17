#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0) dp[i][j] = j;
			else if (j == 0) dp[i][j] = i;
			else if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = 1 + min({
				dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
		}
	}

	cout << dp[n][m];

	return 0;
}
