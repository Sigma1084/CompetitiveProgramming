#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;

    ll ans = n * k;
    n += n % 10;
    k -= 1;
    ans = max(ans, n * k);

    if (n % 10 == 0) {
        cout << ans;
        return;
    }

    // Every 4 moves, we are increasing by 2 + 4 + 6 + 8
    for (int i = 0; i < 4 and k; ++i, --k) {
        /**
         * We need to find (n + 20m)(k - 4m) for m = 0, ..., k/4
         * f(m) = nk - 4nm + 20mk - 80m^2
         * f'(m) = -4n + 20k - 160m
         * f'(m) = 0 => m = (5k - n) / 40 (floor and ceil)
         */
        ll m = (5 * k - n) / 40;
        m = max(0LL, m);
        m = min(m, k / 4);
        ans = max(ans, (n + 20 * m) * (k - 4 * m));

        m = min(m + 1, k / 4);
        ans = max(ans, (n + 20 * m) * (k - 4 * m));

        n += n % 10;
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
