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

    vector<int> p(n);
    for (auto &x: p) {
        cin >> x;
        --x;
    }

    // Ranges
    vector<array<int, 2>> rngs;

    for (int i = 0; i < n; ++i) {
        // i to p[i]
        if (p[i] >= i) {
            rngs.push_back({i, - p[i]});
            rngs.push_back({i + n, - p[i] - n});
        } else {
            rngs.push_back({i, - p[i] - n});
        }
    }

    // SORT l ASC, R DESC
    sort(rngs.begin(), rngs.end());

    vector<int> ans(n);
    OSet<pair<int, int>> oset2;
    for (int i = int(rngs.size()) - 1; i >= 0; --i) {
        auto [l, r] = rngs[i];
        r = -r;
        // Number of ranges with r' <= r
        ans[r % n] = r - l - oset2.order_of_key({r + 1, -1});
        oset2.insert({r, i});
    }

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
