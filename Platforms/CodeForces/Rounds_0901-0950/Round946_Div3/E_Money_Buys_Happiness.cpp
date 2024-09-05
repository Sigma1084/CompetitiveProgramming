#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

void solve() {
    int m, x;
    cin >> m >> x;

    vector<array<int, 2>> a(m);
    int HP = 0;
    for (auto &[c, h]: a) {
        cin >> c >> h;
        HP += h;
    }

    /**
     * dp[hp] := Minimum cost to achieve happiness hp
     */
    vector<ll> dp(HP + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < m; ++i) {
        auto [c, h] = a[i];
        for (int hp = HP; hp >= h; --hp) {
            if (dp[hp - h] + c <= 1LL * x * i) {
                dp[hp] = min(dp[hp], dp[hp - h] + c);
            }
        }
    }

    int ans = 0;
    for (int hp = HP; hp >= 0; --hp) {
        if (dp[hp] < INF) {
            ans = hp;
            break;
        }
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
