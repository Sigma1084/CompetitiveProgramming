#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 2e5;
array<int, N + 1> prec() {
    array<int, N + 1> dp{};
    for (int i = 1; i <= N; i *= 3) {
        dp[i] = 1;
    }
    partial_sum(dp.cbegin(), dp.cend(), dp.begin());
    partial_sum(dp.cbegin(), dp.cend(), dp.begin());
    return dp;
};
auto dp = prec();

void solve() {
    int l, r;
    cin >> l >> r;
    cout << dp[r] - dp[l-1] + dp[l] - dp[l-1];
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
