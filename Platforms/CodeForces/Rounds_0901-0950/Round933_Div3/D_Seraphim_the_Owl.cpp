#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }

    ll cur = 0, ans = LLONG_MAX;
    for (int i = m; i < n; ++i) {
        cur += min(a[i], b[i]);
    }
    for (int i = m-1; i >= 0; --i) {
        ans = min(ans, cur + a[i]);
        cur += b[i];
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
