#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x, y, z;
    ll k;
    cin >> x >> y >> z >> k;

    ll ans = 0;
    for (int a = 1; a <= x; ++a) {
        if (k % a) continue;
        for (int b = 1; b <= y; ++b) {
            ll c = k / a / b;
            if (a * b * c == k and c <= z) {
                ans = max(ans, 1LL * (x - a + 1) * (y - b + 1) * (z - c + 1));
            }
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
