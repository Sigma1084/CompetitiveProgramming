#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> fr(n + 1);
    for (int i = 0; i < n; ++i) {
        fr[a[i]] += 1;
    }

    vector<ll> dp(n + 1);
    vector<int> take(n + 1, true);
    for (int i = n; i >= 1; --i) {
        int s = 0;
        for (auto j = i; j <= n; j += i) {
            if (fr[i] > 0) {
                take[j] = false;
            }
            dp[i] -= dp[j];
            s += fr[j];
        }
        dp[i] += 1LL * s * (s - 1) / 2;
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (take[i]) {
            ans += dp[i];
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
