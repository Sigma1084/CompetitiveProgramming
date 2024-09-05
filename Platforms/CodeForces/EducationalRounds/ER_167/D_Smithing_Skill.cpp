#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e6;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> a(n);
    for (auto &[l, g]: a) {
        cin >> l;
    }
    for (auto &[l, g]: a) {
        cin >> g;
    }

    vector<int> c(m);
    for (auto &x: c) {
        cin >> x;
    }

    array<int, N + 1> minLoss;
    iota(minLoss.begin(), minLoss.end(), 1);

    for (auto [l, g]: a) {
        minLoss[l] = min(minLoss[l], l - g);
    }
    for (int i = 1; i <= N; ++i) {
        if (minLoss[i-1] < i) {
            minLoss[i] = min(minLoss[i], minLoss[i - 1]);
        }
    }

    int best = minLoss[N];

    ll ans = 0;
    for (auto &x: c) {
        // Let's port away the extra
        if (x >= N) {
            int extra = (x - N + best - 1) / best;
            x -= extra * best;
            ans += 2 * extra;
        }
    }

    array<int, N + 1> dp;
    fill(dp.begin(), dp.end(), 0);
    for (int i = 1; i <= N; ++i) {
        if (minLoss[i] <= i) {
            dp[i] = dp[i - minLoss[i]] + 2;
        }
    }

    for (const auto &x: c) {
        ans += dp[x];
    }

    cout << ans;

    return 0;
}
