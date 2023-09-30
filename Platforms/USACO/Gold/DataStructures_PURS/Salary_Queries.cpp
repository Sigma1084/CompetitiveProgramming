#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<typename T>
using ordered_set = __gnu_pbds::tree<T,
    __gnu_pbds::null_type,
    std::less<T>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, nQ;
    cin >> n >> nQ;

    vector<int> a(n);
    ordered_set<array<int, 2>> os;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        os.insert({a[i], i});
    }

    for (int k, x, l, u; nQ--; ) {
        char t;
        cin >> t;
        if (t == '!') {
            cin >> k >> x; k--;
            os.erase({a[k], k});
            a[k] = x;
            os.insert({a[k], k});
        } else if (t == '?') {
            cin >> l >> u;
            cout << os.order_of_key({u + 1, 0}) 
                    - os.order_of_key({l, 0}) << '\n';
        } else {
            assert(false);
        }
    }

    return 0;
}
