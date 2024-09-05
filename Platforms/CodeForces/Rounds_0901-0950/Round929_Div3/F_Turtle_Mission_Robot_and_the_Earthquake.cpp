#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector b(n, vector<int>(m));
    for (auto &r: b) {
        for (auto &x: r) {
            cin >> x;
        }
    }

    // Suppose I am at (n-1, j) but i has gone to n-1
    // What is the minimum I need?
    vector dpD(n, vector<int>(m));
    for (int )

    vector dp(n, vector<bool>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // i + j time has passed
            if (b[(i + i + j) % n][j] == 1) {
                dp[i][j] = false;
                continue;
            }
            if (i) {
                dp[i][j] = dp[i][j] or dp[i - 1][j];
            }
            if (j) {
                dp[i][j] = dp[i][j] or dp[i][j - 1];
            }
        }
    }


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
