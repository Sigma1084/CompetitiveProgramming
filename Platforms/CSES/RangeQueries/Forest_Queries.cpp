#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, nQ;
    cin >> n >> nQ;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (c == '*');
        }
    }

    for (int r1, c1, r2, c2; nQ; nQ--) {
        cin >> r1 >> c1 >> r2 >> c2;
        tie(r1, r2) = minmax(r1, r2);
        tie(c1, c2) = minmax(c1, c2);
        cout << dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1] << '\n';
    }

    return 0;
}