#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans(n);
    ans[0] = a[0];
    for (int i = 1; i < n; ++i) {
        ans[i] = (m / a[i]) * a[i];
        if (a[i] == a[i-1]) continue;
        while (gcd(ans[i], a[i-1]) != a[i]) {
            ans[i] -= a[i];
        }
    }

    for (auto x: ans) {
        cout << x << ' ';
    }
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
