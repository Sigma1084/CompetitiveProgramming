#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int l, n, m;
    cin >> l >> n >> m;

    vector<int> a(l);
    for (auto &x: a) {
        cin >> x;
    }

    vector<vector<int>> b(n, vector<int>(m));
    for (auto &x: b) {
        for (auto &y: x) {
            cin >> y;
        }
    }

    // dp[lI][i][j] := Max score when we use first lI and end at i, j
    vector dp(l, vector(n, vector(m, -1)));

    // Suppose 0 elements have been taken and we're doing dp[0][i][j]
    // In the submatrix (i, n) x (j, m), if P1 can win any 1 of dp[1], P1 wins [i][j]
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
