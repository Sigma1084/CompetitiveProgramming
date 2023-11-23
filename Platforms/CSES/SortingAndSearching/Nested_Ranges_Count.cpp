#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

template <typename T, class Compare = std::less<>>
using OSet = __gnu_pbds::tree<T,
    __gnu_pbds::null_type,
    Compare,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 1;
    std::cin >> n;

    vector<array<int, 3>> ranges(n);
    for (int i = 0; i < n; ++i) {
        auto &[l, r, idx] = ranges[i];
        cin >> l >> r;
        idx = i;
    }

    // SORT l ASC, R DESC
    sort(ranges.begin(), ranges.end(), [](auto a, auto b) {
        auto [l1, r1, idx1] = a;
        auto [l2, r2, idx2] = b;
        if (l1 != l2) {
            return l1 < l2;
        }
        return r1 > r2;
    });

    vector<int> c(n), C(n);

    OSet<pair<int, int>, greater<>> oset1;
    for (int i = 0; i < n; ++i) {
        auto [l, r, idx] = ranges[i];
        // Number of ranges with r' >= r
        c[idx] = oset1.order_of_key({r, -1});
        oset1.insert({r, i});
    }

    OSet<pair<int, int>> oset2;
    for (int i = n - 1; i >= 0; --i) {
        auto [l, r, idx] = ranges[i];
        // Number of ranges with r' <= r
        C[idx] = oset2.order_of_key({r + 1, -1});
        oset2.insert({r, i});
    }

    for (int x: C) {
        cout << x << ' ';
    }
    cout << '\n';

    for (int x: c) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
