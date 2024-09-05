#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Compare = std::less<>>
using OSet = __gnu_pbds::tree<T,
    __gnu_pbds::null_type,
    Compare,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

/**
 * For every i, find the number of j such that
 * s[i] <= s[j] <= e[j] <= e[i]
 */

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (auto &[l, r]: a) {
        cin >> l >> r;
    }
    sort(a.begin(), a.end(), [](auto &x, auto &y) {
        return x[1] < y[1];
    });

    ll ans = 0;
    OSet<array<int, 2>> s;
    for (int i = 0; i < n; ++i) {
        auto [l, r] = a[i];
        ans += s.size() - s.order_of_key({l, -1});
        s.insert({l, i});
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
