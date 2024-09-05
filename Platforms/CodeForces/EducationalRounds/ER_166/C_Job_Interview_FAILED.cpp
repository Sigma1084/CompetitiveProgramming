#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> a(n + m + 1);
    for (auto &[p, t]: a) {
        cin >> p;
    }
    for (auto &[p, t]: a) {
        cin >> t;
    }

    // Moving to other must increase by some amount
    // Let us make everyone programmers for now

    set<array<int, 2>> pt, tp;
    ll ans = 0;
    for (int i = 0; i < n + m + 1; ++i) {
        auto [p, t] = a[i];
        ans += p;
        pt.insert({t - p, i});
    }

    // Move m ppl to testers
    for (int _ = 0; _ < m; ++_) {
        auto [d, i] = *pt.rbegin();  // Most increase
        pt.erase({d, i});
        ans += d;
        tp.insert({-d, i});
    }

    for (int i = 0; i < n + m + 1; ++i) {
        auto [p, t] = a[i];
        if (pt.count({t - p, i})) {
            cout << ans - p << ' ';
            continue;
        }
        // He is a tester right now
        cout << ans - t + (*pt.begin())[0] << ' ';
    }
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
