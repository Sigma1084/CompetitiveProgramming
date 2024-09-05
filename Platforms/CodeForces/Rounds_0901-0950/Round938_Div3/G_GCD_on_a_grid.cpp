#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int A = 1e6;

void solve() {
    int n, m;
    cin >> n >> m;

    vector a(n, vector(m, 0));
    for (auto &v: a) {
        for (auto &x: v) {
            cin >> x;
        }
    }

    vector dp(n, vector(m, vector<int>()));
    for (int x = 1; x <= A; ++x) {
        if (a[0][0] % x == 0) {
            dp[0][0].push_back(x);
        }
    }

    for (int j = 1; j < m; ++j) {
        for (auto x: dp[0][j-1]) {
            if (a[0][j] % x == 0) {
                dp[0][j].push_back(x);
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        for (auto x: dp[i-1][0]) {
            if (a[i][0] % x == 0) {
                dp[i][0].push_back(x);
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            auto i1 = dp[i-1][j].begin(), i2 = dp[i][j-1].begin();
            while (i1 != dp[i-1][j].end() and i2 != dp[i][j-1].end()) {
                if (*i1 == *i2) {
                    if (a[i][j] % *i1 == 0) {
                        dp[i][j].push_back(*i1);
                    }
                    ++i1;
                    ++i2;
                } else if (*i1 < *i2) {
                    if (a[i][j] % *i1 == 0) {
                        dp[i][j].push_back(*i1);
                    }
                    ++i1;
                } else {
                    if (a[i][j] % *i2 == 0) {
                        dp[i][j].push_back(*i2);
                    }
                    ++i2;
                }
            }
            while (i1 != dp[i-1][j].end()) {
                if (a[i][j] % *i1 == 0) {
                    dp[i][j].push_back(*i1);
                }
                ++i1;
            }
            while (i2 != dp[i][j-1].end()) {
                if (a[i][j] % *i2 == 0) {
                    dp[i][j].push_back(*i2);
                }
                ++i2;
            }
            dp[i-1][j].clear();
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cerr << "dp[" << i << "][" << j << "]: ";
    //         for (auto x: dp[i][j]) {
    //             cerr << x << ' ';
    //         }
    //         cerr << '\n';
    //     }
    // }

    cout << dp[n-1][m-1].back();
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
