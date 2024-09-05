#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a, b, m;
    cin >> a >> b >> m;

    // Suppose the first one is a
    ll ans = (a + m) / a + (b + m) / b;
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
