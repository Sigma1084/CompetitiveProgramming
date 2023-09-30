#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Import oset
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ll ans = 0;
        oset<int> s;
        // s.order_of_key(x): #(y in s s.t. y < x)

        for (int x; n--; ) {
            cin >> x;
            ans += s.size() - s.order_of_key(x + 1);
            s.insert(x);
        }

        cout << ans << '\n';
    }

    return 0;
}
