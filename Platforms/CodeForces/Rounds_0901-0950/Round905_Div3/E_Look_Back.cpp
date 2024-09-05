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

    constexpr long long INF = 2e9 + 5;

    int prev = 0, cur;
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i-1]) {
            // Ideal case.
            // prev will be 0
            assert(prev == 0);
            continue;
        }

        cur = 1;
        while (2LL*a[i] < 1LL*a[i-1]) {
            a[i] *= 2;
            ans += 1;
        }
        cur += prev;

        // a[i-1] > 2 * a[i] >= a[i-1]
        // Some prev is also there
        ans += cur;

        // Make a[i] as huge as possible
        prev = cur;
        while (2LL * a[i] <= INF and prev > 0) {
            prev--;
            a[i] *= 2;
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
