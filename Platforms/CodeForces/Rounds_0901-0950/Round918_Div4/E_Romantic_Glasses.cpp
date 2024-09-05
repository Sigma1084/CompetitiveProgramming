#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * Store se - so for every i
 * f[j] - f[i] must be 0 for some i, j
 * or they should be the same
 */

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    map<ll, int> m;
    m[0] = 1;

    ll s = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            s += a[i];
        } else {
            s -= a[i];
        }
        m[s]++;
    }

    for (auto [_, v]: m) {
        if (v >= 2) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
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
