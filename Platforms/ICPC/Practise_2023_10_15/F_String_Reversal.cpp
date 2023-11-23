#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <typename T>
using OSet = __gnu_pbds::tree<T,
    __gnu_pbds::null_type,
    std::less<>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;

    vector<queue<int>> pos(26);
    OSet<pair<int, char>> oset;

    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].push(i);
        oset.insert({i, s[i]});
    }

    reverse(s.begin(), s.end());

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        // We need t[i]
        auto req = make_pair(pos[s[i] - 'a'].front(), s[i]);
        ans += oset.order_of_key(req);
        oset.erase(oset.lower_bound(req));
        pos[s[i] - 'a'].pop();
    }

    cout << ans << '\n';

    return 0;
}
