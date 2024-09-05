#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, c;
    cin >> n >> c;

    // We compute all first
    ll ans = 1LL * (c + 1) * (c + 2) / 2;

    vector<int> a(n), odds, evens;
    for (auto &x: a) {
        cin >> x;
        ans -= (x + 2) / 2;
        if (x % 2) {
            odds.push_back(x);
        } else {
            evens.push_back(x);
        }
    }

    for (int x: a) {
        // Erase all pairs such that (y - x = a[i])
        // AND (y - x NOT in any of the removals)
        // Has the same parity
        // The range is [0, c - x]
        // How many of these have the same parity and lie in the range
        int plus = 0;
        if (x % 2 == 0) {
            plus = upper_bound(evens.begin(), evens.end(), 2*c - x) 
                - evens.begin();
            plus -= lower_bound(evens.begin(), evens.end(), x) 
                - evens.begin();
        } else {
            plus = upper_bound(odds.begin(), odds.end(), 2*c - x) 
                - odds.begin();
            plus -= lower_bound(odds.begin(), odds.end(), x)
                - odds.begin();
        }
        ans -= c - x + 1;
        ans += plus;
    }

    cout << ans;
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
