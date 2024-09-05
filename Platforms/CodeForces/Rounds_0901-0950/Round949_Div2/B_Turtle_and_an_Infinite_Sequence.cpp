#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    /**
     * m = 0 => n = n
     * m = 1 => n = n - 1 | n | n + 1
     * m = 2 => n = n - 2 | n - 1 | n | n + 1 | n + 2
     */
    ll l = max(0, n - m), r = n + m;
    // We need l | l + 1 | ... | r
    ll ans = l;
    for (int i = 0; i <= 30; ++i) {
        ll j = (1 << i);
        if (l & j) {
            continue;
        }
        if (l - l % j + j <= r) {
            ans |= j;
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
