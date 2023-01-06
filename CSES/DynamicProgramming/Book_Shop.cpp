#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, money; cin >> n >> money;
    vector<pair<int, int>> a(n); 
    for (auto &i: a) cin >> i.first;
    for (auto &i: a) cin >> i.second;

    sort(a.begin(), a.end());

    vector<vector<int>> dp(n+1, vector<int>(money+1, 0));
    for (int i=1; i<=n; i++) {
        for (int mon=1; mon<=money; mon++) {
            dp[i][mon] = dp[i-1][mon];
            if (mon >= a[i-1].first) {
                int newProfit = a[i-1].second + dp[i-1][mon-a[i-1].first];
                dp[i][mon] = max(dp[i][mon], newProfit);
            }
        }
    }

    cout << dp[n][money];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }

    return 0;
}
