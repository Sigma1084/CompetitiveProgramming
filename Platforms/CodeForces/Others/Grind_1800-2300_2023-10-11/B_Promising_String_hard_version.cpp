#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <typename T>
using oset = __gnu_pbds::tree<T,
    __gnu_pbds::null_type,
    std::less<>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

/**
 * p[i] := Number of '+' in [0, i]
 * m[i] := Number of '-' in [0, i]
 * 
 * As long as m[i] >= p[i] and m[i] - p[i] = 0 (mod 3),
 * we can convert all extra minuses to pluses
 * 
 * So, maintain m[i] - p[i] for all i and 
 * Count the number of pairs (i, j) such that
 * m[i] - p[i] >= m[j] - p[j] and m[i] - p[i] = m[j] - p[j] (mod 3)
 * 
 * Store all d[i] = m[i] - p[i] in a set
 */
void solve() {
    int n; cin >> n;
    string s; cin >> s;

    array<oset<pair<int, int>>, 3> fs;
    fs.fill(oset<pair<int, int>>());

    ll ans = 0;
    fs[0].insert({0, 0});
    int p = 0;

    auto convertMod3 = [&](int d) {
        return (d % 3 + 3) % 3;
    };

    for (int i = 0, d, d3; i < n; ++i) {
        p += s[i] == '+';
        d = i+1 - 2*p;
        d3 = convertMod3(d);
        ans += fs[d3].order_of_key({d, i+1});
        fs[d3].insert({d, i+1});
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
