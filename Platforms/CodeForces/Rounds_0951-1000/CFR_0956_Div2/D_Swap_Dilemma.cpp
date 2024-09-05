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
    int n, x;
    cin >> n;

    vector<int> a(n), b(n);
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;

    if (set(a.begin(), a.end()) != set(b.begin(), b.end())) {
        cout << "NO";
        return;
    }

    ll d = 0;

    OSet<int, greater<>> os;
    for (int x: a) {
        d += os.order_of_key(x);
        os.insert(x);
    }

    os.clear();
    for (int x: b) {
        d += os.order_of_key(x);
        os.insert(x);
    }

    cout << (d % 2 ? "NO" : "YES");
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
