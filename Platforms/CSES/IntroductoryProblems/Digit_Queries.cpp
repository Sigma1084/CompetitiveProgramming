#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * 8 => 8*1
 * 12 => 9*1 + 3*2
 * 123 => 9*1 + 90*2 + 24*3
 */
ll f(ll k) {
    ll res = 0;
    for (ll i = 1, v = 9; k; ++i, v *= 10) {
        res += i * min(k, v);
        k -= min(k, v);
    }
    return res;
}

constexpr ll K = 1e17;

void solve() {
    ll m;
    cin >> m;

    auto range = std::ranges::iota_view(1LL, K + 1);
    ll k = *std::ranges::lower_bound(range, m, std::less<>(), f);
    m -= f(k - 1);

    string s = to_string(k);
    cout << s[m - 1];
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
