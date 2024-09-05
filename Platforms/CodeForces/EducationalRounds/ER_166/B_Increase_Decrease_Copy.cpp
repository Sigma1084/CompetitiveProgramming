#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n + 1);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }

    ll cur = 1;
    for (int i = 0; i < n; ++i) {
        cur += abs(a[i] - b[i]);
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        if (min(a[i], b[i]) <= b[n] and b[n] <= max(a[i], b[i])) {
            ans = cur;
            break;
        } else {
            ans = min(ans, cur + min(abs(a[i] - b[n]), abs(b[i] - b[n])));
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

