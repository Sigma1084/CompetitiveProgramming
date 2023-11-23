#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    ll ans = 0;
    int o = 0;

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            ans += o;
            cout << ans << ' ';
        } else {
            o += 1;
        }
    }

    while (o--) {
        cout << -1 << ' ';
    }
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
