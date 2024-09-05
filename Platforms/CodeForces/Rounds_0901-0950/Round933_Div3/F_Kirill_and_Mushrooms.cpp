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

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), p(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: p) {
        cin >> x;
        --x;
    }

    OSet<pair<int, int>, greater<>> s;
    for (int i = 0; i < n; ++i) {
        s.insert({a[i], i});
    }

    pair<ll, int> ans = {0, 0};
    for (int k = 0; k < n; ++k) {
        // Take exactly k + 1 of them
        if (s.size() < k + 1) {
            break;
        }
        int cur = s.find_by_order(k)->first;
        ans = max(ans, {1LL * (k + 1) * cur, -(k + 1)});
        s.erase({a[p[k]], p[k]});
    }

    cout << ans.first << ' ' << -ans.second;
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
