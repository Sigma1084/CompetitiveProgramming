#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<typename T>
using __ordered_mset = __gnu_pbds::tree<T,
    __gnu_pbds::null_type,
    std::less_equal<T>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

template<typename T>
struct OrderedMultiset: __ordered_mset<T> {
    using __ordered_mset<T>::__ordered_mset;

    /**
     * less_equal operator interchanges lower_bound and upper_bound
     */

    int count(T val) const {
        return this->order_of_key(val + 1) - this->order_of_key(val);
    }

    void eraseOne(T val) {
        if (count(val)) {
            this->erase(this->upper_bound(val));
        }
    }

    void eraseAll(T val) {
        for (int i = count(val); i; i--) {
            this->erase(this->upper_bound(val));
        }
    }

    int order_of_key_first(T val) {
        return this->order_of_key(val);
    }

    int order_of_key_last(T val) {
        return this->order_of_key(val + 1) - 1;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    OrderedMultiset<int> sB, sE;

    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
        sE.insert(x);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sE.eraseOne(a[i]);
        ans += (sB.size() - sB.order_of_key(a[i] + 1)) 
                * sE.order_of_key(a[i]);
        sB.insert(a[i]);
    }

    cout << ans << '\n';

    return 0;
}
