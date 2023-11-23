#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * f[k] := #(1234...k)
 * g[k] := #(112...1..k)
 * g[k] = g[k-1] + f[k]
 * 
 * g[8] = 1 + 2 + ... + 8 = (8 occurs once) + ... (1 occurs 8 times)
 * g[16] = (1 occurs 16 times) + (2 occurs 15 times) + ... + (16 occurs 1 time)
 * g[16] = 2 * (1 + 2 + ... + 7) + (8 + 9 + ... + 16)
 *              16  15        10    9   8         1
 * g[120] = 3 * (1 + ... + 21) + 2 * (22 + ... + 111) + (112 + ... + 120)
 *              120        100        99          10      9           1
 * 
 * g[10] = 2 * (1) + (2 + 3 + ... + 10) = 55 + 1
 * 
 * g(40) = 2 * (1 + 2 + ... + 31) + (32 + ... + 40)
 *              40            10     9           1
 */

ll consecSum(ll a, ll b) {
    return (a + b) * (b - a + 1) / 2;
}

ll g(ll k) {
    if (k == 0) return 0;
    ll ans = 0;
    ll d = 1;
    int t = 1;
    while (k > 0) {
        ll a = max(1LL, k - 9*d + 1);
        ans += t * consecSum(a, k);
        k -= 9*d;
        d *= 10;
        ++t;
    }
    return ans;
}

ll f(ll k) {
    if (k == 0) return 0;
    return g(k) - g(k-1);
}

ll K = 1;
void preComputeMaxK() {
    K = 1E7;
    while (g(K) < 1E18 + 1E17) {
        K += 1E7;
    }
}

void solve() {
    ll n;
    cin >> n;

    auto range = ranges::iota_view(1LL, K + 1);
    ll k = *ranges::lower_bound(range, n, std::less<>(), g);
    n -= g(k-1);

    // The answer is now the nth digit in 123456...k

    range = ranges::iota_view(1LL, k);
    ll i = *ranges::lower_bound(range, n, std::less<>(), f);
    n -= f(i-1);

    // The answer is now the nth digit in i

    string s = to_string(i);
    cout << s[n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    preComputeMaxK();

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
