#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (auto &y: a) {
        cin >> y;
    }

    if (x == 0) {
        int ans = 0, cur = 0;
        for (auto y: a) {
            cur ^= y;
            ans += cur == 0;
        }
        cout << (cur == 0 ? ans : -1);
        return;
    }

    int ans = 0;

    // We have gotten rid of extra
    for (int b = 29; b >= 0; --b) {
        bool ok = true;
        for (auto y: a) {
            if (y > x) ok = false;
        }
        if (ok) {
            ans = max(ans, int(a.size()));
        }

        // We can make everything the b-th bit 0
        vector<int> na;
        bool merge = false;
        for (auto y: a) {
            if (merge) {
                na.back() ^= y;
            } else {
                na.push_back(y);
            }
            if (y & (1 << b)) {
                merge = !merge;
            }
        }

        ok = true;
        for (auto y: na) {
            if (y > x) ok = false;
        }
        if (ok) {
            ans = max(ans, int(na.size()));
        }

        // If x does not have the b-th bit, just set a = na
        if (!(x & (1 << b))) {
            if (merge) {
                break;
            }
            a = move(na);
            continue;
        }

        // cerr << "b = " << b << '\n';
        // cerr << "na.size() = " << na.size() << '\n';
        // cerr << "merge = " << merge << '\n';

        // If we can do it, we will try and do it
        if (not merge) {
            ans = max(ans, int(na.size()));
        }
    }

    ans == 0 ? cout << -1 : cout << ans;
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
