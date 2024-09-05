#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int D = 20;
constexpr int N = 200000;

constexpr array<array<int, D>, N + 1> preComp() {
    array<array<int, D>, N + 1> dp{};
    for (int n = 1; n <= N; ++n) {
        for (int d = 0; d < D; ++d) {
            dp[n][d] = dp[n-1][d] + ((n >> d) & 1);
        }
    }
    return dp;
}
auto dp = preComp();

void solve() {
    int l, r;
    cin >> l >> r;

    int ans = INT_MAX;
    for (int d = 0; d < D; ++d) {
        ans = min(ans, r - l + 1 - dp[r][d] + dp[l-1][d]);
    }
    cout << ans;
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
