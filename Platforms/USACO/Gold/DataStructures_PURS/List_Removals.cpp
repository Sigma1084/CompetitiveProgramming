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

    int n;
    cin >> n;
    
    ordered_set<std::array<int, 2>> os;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        os.insert({i, x});
    }

    for (int i = 0, x; i < n; ++i) {
        cin >> x; x--;
        // Remove the x-th element
        std::cout << os.find_by_order(x)->at(1) << ' ';
        os.erase(os.find_by_order(x));
    }

    return 0;
}
