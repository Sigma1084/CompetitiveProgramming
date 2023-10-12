#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n);
    dp[n-1] = 1;

    for (int i = n-2; i >= 0; --i) {
        // Either remove current element
        dp[i] = dp[i+1] + 1;

        // Keep the current element
        if (a[i] + i < n) {
            // We can keep everything
            if (a[i] + i + 1 < n) {
                dp[i] = min(dp[i], dp[i + a[i] + 1]);
            } else {
                dp[i] = 0;
            }
        }
    }

    cout << dp[0];
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
