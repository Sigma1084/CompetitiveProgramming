#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    /**
     * We can achieve
     * 1 2 3 ... n
     * 2 2 3 ... n
     * 3 3 3 ... n
     * . . . ... .
     * n n n ... n
     */

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += i * (2 * i - 1);
    }
    cout << res << ' ' << 2 * n << '\n';

    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    for (int i = n; i >= 1; --i) {
        for (int c: {1, 2}) {
            cout << c << ' ' << i << ' ';
            for (auto x: p) {
                cout << x << ' ';
            }
            cout << '\n';
        }
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
