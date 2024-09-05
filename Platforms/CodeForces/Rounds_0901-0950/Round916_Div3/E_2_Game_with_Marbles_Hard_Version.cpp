#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * Do something with a[i] - b[i]
 */

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }

    set<array<int, 3>, greater<>> sa, sb;
    for (int i = 0; i < n; ++i) {
        sa.insert({a[i], b[i], i});
        sb.insert({b[i], a[i], i});
    }

    ll ans = 0;
    for (int t = 0, k = 1; t < n; ++t, k *= -1) {
        int i = (*sa.begin())[2];
        int j = (*sb.begin())[2];

        if (a[i] - b[j] <= a[j] - b[i]) {
            i = j;
        }
        ans += k * (a[i] - 1);

        sa.erase({a[i], b[i], i});
        sb.erase({b[i], a[i], i});

        swap(a, b);
        swap(sa, sb);
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
