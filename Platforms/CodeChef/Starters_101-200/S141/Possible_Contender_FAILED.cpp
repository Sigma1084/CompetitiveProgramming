#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (auto &[x, i]: a) {
        cin >> x;
    }
    for (int i = 0; i < n; ++i) {
        a[i][1] = i;
    }
    sort(a.begin(), a.end(), greater<>());

    set<pair<int, int>> rs;
    rs.emplace(0, n - 1);
    string ans(n, '0');
    int av = 0;
    for (int i = 0, j; i < n; i = j) {
        for (j = i + 1; j < n and a[j][0] == a[i][0]; ++j);
        av += j - i;
        for (int k = i; k < j; ++k) {
            int p = a[k][1];
            auto it = prev(rs.upper_bound({p, p}));
            auto [l, r] = *it;
            rs.erase(it);
            if (l <= p - 1) {
                rs.emplace(l, p - 1);
            }
            if (p + 1 <= r) {
                rs.emplace(p + 1, r);
            }
        }
        if (av - 1 >= rs.size()) {
            for (int k = i; k < j; ++k) {
                ans[a[k][1]] = '1';
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
