#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<int> dp(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        // Find j such that a[i] + ... + a[j] >= l
        int j = lower_bound(pref.begin(), pref.end(), pref[i] + l) - pref.begin() - 1;
        dp[i] = dp[i + 1];
        if (j < n and pref[j+1] - pref[i] <= r) {
            dp[i] = max(dp[i], 1 + dp[j + 1]);
        }
    }

    cout << dp[0];
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
