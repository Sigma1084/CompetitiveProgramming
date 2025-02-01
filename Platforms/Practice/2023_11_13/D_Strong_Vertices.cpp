#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    valarray<int> a(n), b(n), c;
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }
    c = a - b;

    int x = c.max();
    int ans = ranges::count_if(c, [x](int y) { return y == x; });

    cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
        if (c[i] == x) {
            cout << i + 1 << ' ';
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
