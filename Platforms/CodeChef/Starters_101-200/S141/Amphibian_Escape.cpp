#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k, h;
    cin >> n >> k >> h;

    ll ans = 1LL * max(0, n - h + 1) * n;
    n = min(n, h - 1);
    for (int d = 1; d < n; ++d) {
        int a = max(h - 1LL * (k - 1) * d, 1LL + d);
        ans += max(0, n - a + 1);
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
