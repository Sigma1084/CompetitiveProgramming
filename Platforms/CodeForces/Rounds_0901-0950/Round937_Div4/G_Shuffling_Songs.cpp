#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<array<string, 2>> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
    }

    vector edge(n, vector(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            edge[i][j] = a[i][0] == a[j][0] or a[i][1] == a[j][1];
        }
    }

    /**
     * dp[mask][i] is true if it is possible for a path
     * to exist ending at the i-th bit
     */
    vector dp(1 << n, vector(n, false));
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = true;
    }

    int ans = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (not dp[mask][i]) {
                continue;
            }
            ans = max(ans, __builtin_popcount(mask));
            for (int j = 0; j < n; ++j) {
                if (!(mask & (1 << j)) and edge[i][j]) {
                    dp[mask | (1 << j)][j] = true;
                }
            }
        }
    }

    cout << n - ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
