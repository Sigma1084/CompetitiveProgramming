#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    if (k >= 3) {
        cout << 0;
        return;
    } else if (k == 0) {
        cout << *min_element(a.begin(), a.end());
        return;
    }

    sort(a.begin(), a.end());

    ll ans = *min_element(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll x = a[j] - a[i];
            ans = min(ans, x);
            if (k == 1) {
                continue;
            }
            // Closest 2 numbers to x
            auto it = lower_bound(a.begin(), a.end(), x);
            if (it != a.end()) {
                ans = min(ans, *it - x);
            }
            if (it != a.begin()) {
                --it;
                ans = min(ans, x - *it);
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
