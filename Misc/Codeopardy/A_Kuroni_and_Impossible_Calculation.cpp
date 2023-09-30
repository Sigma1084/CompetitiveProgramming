#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (ll &x: a) cin >> x;

    if (n > m) {
        cout << 0 << '\n';
        return 0;
    }

    ll ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans *= abs(a[i] - a[j]);
            ans %= m;
        }
    }

    cout << ans << '\n';

    return 0;
}
