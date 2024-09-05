#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    int sx, sy;
    cin >> sx >> sy;
    --sx, --sy;

    vector<vector<int>> a(n, vector<int>(m));
    for (auto &v: a) {
        for (auto &x: v) {
            cin >> x;
        }
    }

    /**
     * dp_k[i][j] := At (i, j) 
     */
    vector dp(n, vector(m, -1LL));
    dp[sx][sy] = 0;

    ll ans = 1LL * k * a[sx][sy];
    for (int _ = 0; _ < 2600 and k--; ++_) {
        vector dp2(n, vector(m, -1LL));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > 0 and dp[i - 1][j] != -1) {
                    dp2[i][j] = max(dp2[i][j], dp[i - 1][j]);
                }
                if (i < n - 1 and dp[i + 1][j] != -1) {
                    dp2[i][j] = max(dp2[i][j], dp[i + 1][j]);
                }
                if (j > 0 and dp[i][j - 1] != -1) {
                    dp2[i][j] = max(dp2[i][j], dp[i][j - 1]);
                }
                if (j < m - 1 and dp[i][j + 1] != -1) {
                    dp2[i][j] = max(dp2[i][j], dp[i][j + 1]);
                }
                if (dp2[i][j] != -1) {
                    dp2[i][j] += a[i][j];
                    ans = max(ans, dp2[i][j] + 1LL * k * a[i][j]);
                }
            }
        }
        swap(dp, dp2);
    }

    cout << ans << '\n';

    return 0;
}
