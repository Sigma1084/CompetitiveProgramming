#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }

    vector<ll> prods(n), pref(n + 1);
    for (int i = 0; i < n; ++i) {
        prods[i] = 1LL * a[i] * b[i];
        pref[i + 1] = prods[i] + pref[i];
    }

    auto get = [&](int l, int r) {
        if (l > r) return 0LL;
        return pref[r + 1] - pref[l];
    };

    vector dp(n, vector(n, 0LL));
    // Reverse from [l, r] is same as reverse from [l+1, r-1] and then reverse

    // d = 0  =>  dp[i][i]
    for (int i = 0; i < n; ++i) {
        dp[i][i] = prods[i];
    }
    for (int i = 0; i + 1 < n; ++i) {
        dp[i][i+1] = 1LL * a[i] * b[i+1] + 1LL * a[i+1] * b[i];
    }

    for (int d = 2; d < n; ++d) {
        for (int i = 0; i + d < n; ++i) {
            dp[i][i+d] = dp[i+1][i+d-1] + 1LL * a[i] * b[i+d] + 1LL * a[i+d] * b[i];
        }
    }

    ll ans = get(0, n-1);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ans = max(ans, get(0, i-1) + dp[i][j] + get(j+1, n-1));
        }
    }

    cout << ans;

    return 0;
}
