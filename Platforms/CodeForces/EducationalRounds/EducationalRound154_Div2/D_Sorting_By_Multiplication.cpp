#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp1(n);
    for (int i = n - 2; i >= 0; i--) {
        dp1[i] = dp1[i + 1] + int(a[i] >= a[i + 1]);
    }

    // What if we make the first i negative and then combine
    vector<int> dp2(n);
    dp2[0] = 1; // Takes 1 operation to make first element negative
    for (int i = 1; i < n; i++) {
        dp2[i] = dp2[i - 1] + int(-a[i] <= -a[i - 1]);
    }

    int ans = min(dp1[0], dp2[n - 1]);
    for (int i = 0; i + 1 < n; i++) {
        // Make the first i negative and then combine
        ans = min(ans, dp2[i] + dp1[i + 1]);
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
