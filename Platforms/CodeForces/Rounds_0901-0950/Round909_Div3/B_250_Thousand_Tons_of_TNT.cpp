#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    ll ans = 0;
    for (int d = 1; d <= n; ++d) {
        if (n % d) continue;
        vector<ll> v;
        for (int i = 0; i < n; ++i) {
            if (i % d == 0) {
                v.push_back(a[i]);
            } else {
                v.back() += a[i];
            }
        }
        ans = max(ans, ranges::max(v) - ranges::min(v));
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
