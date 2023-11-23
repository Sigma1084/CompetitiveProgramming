#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q, x;
    cin >> n >> q;

    for (int i = 1; i + 1 <= n; ++i) {
        cout << i << ' ' << i + 1 << '\n';
    }

    int y = n - 1;

    while (q--) {
        cin >> x;
        if (x == y) {
            cout << "-1 -1 -1\n";
        } else {
            cout << n << ' ' << y << ' ' << x << "\n";
        }
        y = x;
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
