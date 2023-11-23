#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

template <typename T>
using OSet = __gnu_pbds::tree<T,
    __gnu_pbds::null_type,
    std::less<T>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, k;
    cin >> n >> k;

    OSet<int> oset;
    for (int i = 1; i <= n; ++i) {
        oset.insert(i);
    }

    for (int i = 0; !oset.empty(); ) {
        // Traverse
        i = (i + k) % oset.size();

        // Print and erase
        cout << *oset.find_by_order(i) << ' ';
        oset.erase(oset.find_by_order(i));
    }

    return 0;
}
