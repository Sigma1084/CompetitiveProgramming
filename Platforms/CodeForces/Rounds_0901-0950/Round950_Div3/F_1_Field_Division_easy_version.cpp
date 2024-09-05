#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<array<int, 3>> a(k);
    for (auto &[x, y, i]: a) {
        cin >> x >> y;
    }
    for (int i = 0; i < k; ++i) {
        a[i][2] = i;
    }
    sort(a.begin(), a.end(), [](auto &a1, auto &a2) {
        if (a1[1] != a2[1]) return a1[1] < a2[1];  // Column
        return a1[0] < a2[0];  // Row
    });

    // In column 1, what is the max we can have?
    map<int, array<int, 2>> mx;
    mx[1] = {1, -1};
    mx[m + 1] = {n + 1, -1};
    for (auto [x, y, i]: a) {
        mx[y] = max(mx[y], {x + 1, i});
    }

    int cur = 0;
    vector<int> rem;
    for (auto [c, arr]: mx) {
        auto [f, i] = arr;
        if (f <= cur) {
            rem.push_back(c);
        }
        cur = max(cur, f);
    }
    for (auto c: rem) {
        mx.erase(c);
    }

    ll tot = 0;
    cur = 1;  // column
    for (auto [c, arr]: mx) {
        auto [f, i] = arr;
        tot += 1LL * (f - cur) * (c - 1);
        cur = f;
    }

    vector<ll> ans(k);
    for (auto [c, arr]: mx) {
        auto [f, i] = arr;
        if (i == -1) continue;
        ans[i] = true;
    }

    cout << tot << '\n';
    for (auto x: ans) {
        cout << x << ' ';
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
