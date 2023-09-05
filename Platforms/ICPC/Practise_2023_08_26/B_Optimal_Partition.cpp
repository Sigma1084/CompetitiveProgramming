#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto getDP = [n] (vector<int> a) {
        vector<int> dp(n);
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = i ? dp[i - 1] : 0;
            if (cur + a[i] > 0) {
                cur += a[i];
                dp[i] += 1;
            } else if (a[i] < 0) {
                cur = 0;
                dp[i]--;
            }
        }
        return dp;
    };

    vector<int> dp1 = getDP(a);
    vector<int> dp2 = getDP(vector<int>(a.rbegin(), a.rend()));
    reverse(dp2.begin(), dp2.end());

    int ans = max(dp1[n - 1], dp2[0]);
    for (int i = 0; i + 1 < n; i++) {
        ans = max(ans, dp1[i] + dp2[i + 1]);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
