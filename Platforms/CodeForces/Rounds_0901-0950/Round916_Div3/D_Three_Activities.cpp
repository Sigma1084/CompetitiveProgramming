#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }
    for (auto &x: c) {
        cin >> x;
    }

    set<array<int, 2>, greater<>> sb, sc;
    for (int i = 0; i < n; ++i) {
        sb.insert({b[i], i});
        sc.insert({c[i], i});
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        sb.erase({b[i], i});
        sc.erase({c[i], i});

        int j = (*sb.begin())[1];
        sc.erase({c[j], j});
        int k = (*sc.begin())[1];
        ans = max(ans, a[i] + b[j] + c[k]);
        sc.insert({c[j], j});

        k = (*sc.begin())[1];
        sb.erase({b[k], k});
        j = (*sb.begin())[1];
        ans = max(ans, a[i] + b[j] + c[k]);
        sb.insert({b[k], k});

        sb.insert({b[i], i});
        sc.insert({c[i], i});
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
