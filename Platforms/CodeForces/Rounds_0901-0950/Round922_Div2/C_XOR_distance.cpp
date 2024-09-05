#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll complete(ll a, ll b) {
    if (a == b) return 0;
    auto x = a ^ b;
    int d = __lg(x);
    return (1LL << (d + 1)) - x;
}

ll maxed(ll a, ll b) {
    return a ^ b;
}

void solve() {
    ll a, b, r;
    cin >> a >> b >> r;

    if (a < b) swap(a, b);
    ll ans = a - b;

    for (int i = 60; i >= 0; --i) {
        auto bit = 1LL << i;
        if (bit > r) continue;

        // Do not use the r
        // Ignore the last i bits
        auto a1 = a / bit * bit, b1 = b / bit * bit;
        if (a1 == b1) {
            ans = min(ans, complete(a % bit, b % bit));
        } else {
            ans = min(ans, (a1 - b1) - maxed(a % bit, b % bit));
        }

        // Use the r
        a1 = a & bit, b1 = b & bit;
        if (a1 ^ b1) {
            a ^= bit;
            b ^= bit;
            r ^= bit;
            if (a < b) swap(a, b);
            ans = min(ans, a - b);
        } else {
            break;
        }
    }

    cout << ans;
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
