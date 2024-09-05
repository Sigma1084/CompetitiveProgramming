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

    vector<vector<int>> b;
    for (auto x: a) {
        if (b.empty() or (b.back().back() & 1) == (x & 1)) {
            b.push_back({x});
        } else {
            b.back().push_back(x);
        }
    }

    int ans = INT_MIN;
    for (const auto &v: b) {
        int cur = 0;
        for (auto x: v) {
            cur += x;
            ans = max(ans, cur);
            if (cur < 0) {
                cur = 0;
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
