#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b, k;
    cin >> a >> b >> k;

    ll l = 0, r = 1e18;
    while (l <= r) {
        ll m = (l + r) / 2;
        ll cur = 1 + m / b;
        cur += (m >= a) * (1 + (m - a) / b);
        if (cur < k) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << l;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
