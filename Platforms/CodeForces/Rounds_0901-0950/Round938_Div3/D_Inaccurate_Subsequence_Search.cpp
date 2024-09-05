#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }

    map<int, int> fa, fb;
    for (auto x: b) {
        ++fb[x];
    }

    int cur = 0;
    for (int i = 0; i < m; ++i) {
        ++fa[a[i]];
        if (fa[a[i]] <= fb[a[i]]) {
            ++cur;
        }
    }

    int ans = cur >= k;
    for (int i = m; i < n; ++i) {
        --fa[a[i - m]];
        if (fa[a[i - m]] < fb[a[i - m]]) {
            --cur;
        }
        ++fa[a[i]];
        if (fa[a[i]] <= fb[a[i]]) {
            ++cur;
        }
        ans += cur >= k;
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
