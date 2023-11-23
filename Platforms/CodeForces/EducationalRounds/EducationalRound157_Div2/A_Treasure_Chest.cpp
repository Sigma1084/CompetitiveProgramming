#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    if (x >= y) {
        cout << x;
    } else if (x + k >= y) {
        cout << y;
    } else {
        cout << y + (y - (x + k));
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
