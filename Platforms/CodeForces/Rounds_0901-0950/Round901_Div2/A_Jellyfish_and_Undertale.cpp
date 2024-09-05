#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b, n;
    cin >> a >> b >> n;

    vector<int> A(n);
    for (auto &x: A) cin >> x;

    ll ans = b;
    for (int x: A) {
        ans += min(a - 1, x);
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
