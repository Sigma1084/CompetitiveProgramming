#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll sum = 0, leastSum = 0;
    ll ans = 0, maxSum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        maxSum = max(maxSum, sum);
        if (sum - maxSum < leastSum) {
            leastSum = sum - maxSum;
            ans = maxSum;
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
