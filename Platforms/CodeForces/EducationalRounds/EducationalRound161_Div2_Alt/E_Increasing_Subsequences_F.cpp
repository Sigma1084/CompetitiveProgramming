#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * 12 => 2 2 3 4
 * Empty -> 1
 * Choose first 2 -> 4
 * Choose second 2 -> 4
 * Choose neither -> 3
 * 
 * 11 -> 1 2 3 (gives profit of 7)
 * We have 4 remaining
 * 
 * 37 => (1 2 3 4 5) + 5
 * 36 => 1 1 2 2 3 4
 * 4 * 9
 * 9 = 1 + 2 * 2 * 2
 * *f(9), 1, x, x + 1, 1
 * f(9) = 1 + 2^3 => 
 * 
 * 36 => 1 2 3 1 4 5
 */

void solve() {
    ll k;
    cin >> k;
    --k;

    vector<int> lgs;
    int ones = 0;
    while (k) {
        int l = std::__lg(k + 1);
        if (l == 1) {
            ++ones;
        } else {
            lgs.push_back(l);
        }
        k -= (1 << l) - 1;
    }

    for (int x: lgs) {
        cerr << x << ' ';
    }
    cerr << '\n';

    int x = 1000;
    reverse(lgs.begin(), lgs.end());

    vector<int> ans;    
    for (int i = 0; i < ones; ++i) {
        ans.push_back(x--);
    }
    if (not lgs.empty()) {
        ans.push_back(1);
        for (auto lg: lgs) {
            for (int i = 0; i < lg; ++i) {
                ans.push_back(x--);
            }
            reverse(ans.end() - lg, ans.end());
        }
    }

    cout << ans.size() << '\n';
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
