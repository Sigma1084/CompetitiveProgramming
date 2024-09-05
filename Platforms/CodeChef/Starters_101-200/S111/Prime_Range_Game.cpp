#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll l, r;
    cin >> l >> r;

    int p;
    cin >> p;

    vector<ll> a;
    for (__int128_t cur = 1; cur <= r; cur *= p) {
        a.push_back(r / cur - (l - 1) / cur);
    }

    auto n = int(a.size());
    for (int i = 0; i + 1 < n; ++i) {
        a[i] -= a[i + 1];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2) {
            ans ^= i;
        }
    }

    cout << (ans ? "First" : "Second");
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
