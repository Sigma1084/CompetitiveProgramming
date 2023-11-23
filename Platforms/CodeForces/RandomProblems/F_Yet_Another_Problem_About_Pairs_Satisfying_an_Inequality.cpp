#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (auto &x: a | std::views::drop(1)) {
        cin >> x;
    }

    // ans[j] := Number of ai < i such that i < j
    ll ans = 0;
    vector<int> dp(n + 2);
    for (int j = 1; j <= n; ++j) {
        dp[j] += dp[j - 1];
        if (a[j] >= j) {
            continue;
        }
        // We want the number of i < aj such that ai < i
        ans += dp[a[j]];
        dp[j+1] += 1;
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
