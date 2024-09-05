#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int h, n;
    cin >> h >> n;

    vector<int> a(n), c(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: c) {
        cin >> x;
    }

    auto isPos = [&](ll m) {
        ll cur = 0;
        for (int i = 0; i < n and cur < h; ++i) {
            cur += 1LL * (m + c[i] - 1) / c[i] * a[i];
        }
        return cur >= h;
    };

    ll L = 1, H = 1e12;
    while (L <= H) {
        ll m = (L + H) / 2;
        if (isPos(m)) {
            H = m - 1;
        } else {
            L = m + 1;
        }
    }

    cout << L;
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
