#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (auto &[x, y]: a) {
        cin >> x >> y;
    }
    map<int, vector<int>, greater<>> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i][0]].push_back(a[i][1]);
    }

    vector<int> mx(mp.size() + 1);
    int i = 1;
    for (auto &[x, ys]: mp) {
        mx[i] = max(mx[i-1], *max_element(ys.begin(), ys.end()));
        ++i;
    }

    int ans = INT_MAX;
    set<int> ys;
    for (int i = 0; i < n; ++i) {
        auto [x, y] = a[i];
        if (i + 1 < n and mx[i+1] >= x) {
            ans = min(ans, mx[i+1] - x);
        } else {
            auto it = ys.lower_bound(x);
            if (it != ys.end()) {
                ans = min(ans, *it - x);
            }
            if (it != ys.begin()) {
                --it;
                ans = min(ans, x - *it);
            }
        }
        ys.insert(y);
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
