#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x, y;
    cin >> x >> y;

    int a, b;
    cin >> a >> b;

    if (x > y) {
        swap(x, y);
    }

    if (2 * a <= b) {
        cout << 1LL * (x + y) * a;
    } else {
        cout << 1LL * x * b + 1LL * (y - x) * a;         
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
