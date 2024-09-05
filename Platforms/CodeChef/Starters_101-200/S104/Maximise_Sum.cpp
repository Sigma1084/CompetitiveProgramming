#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<int> l(n), r(n);
    l[0] = a[0];
    for (int i = 1; i < n; ++i) {
        l[i] = max(l[i-1], a[i]);
    }
    r[n-1] = a[n-1];
    for (int i = n-2; i >= 0; --i) {
        r[i] = max(r[i+1], a[i]);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += min(l[i], r[i]);
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
