#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/**
 * If we have k < n, then we can always pair single single
 * If k >= n, then we need to 
 */
void solve() {
    int n, k;
    cin >> n >> k;

    vector<array<int, 4>> ans;
    ans.reserve(n);
    auto add = [&](int x1, int y1, int x2, int y2) {
        ans.push_back({x1, y1, x2, y2});
    };
    auto cont = [&n](int l) {
        return l*(l-1)/2 + l*(n-l);
    };

    int l = 0;
    while (l+1 <= n and k - cont(l+1) >= 0) {
        ++l;
    }

    for (int i = 0; i < l; ++i) {
        add(1, 1, 1000, 1000);
    }

    k -= cont(l);
    n -= l;

    assert(k == 0 or k < n);
    if (k) {
        for (int x = 1; x <= k + 1; ++x, --n) {
            add(x, 2, x + 1, 2);
        }
    }

    for (int x = 1; x <= n; ++x) {
        add(x, 3, x, 3);
    }

    cout << "Possible\n";
    for (auto [x1, y1, x2, y2] : ans) {
        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
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
