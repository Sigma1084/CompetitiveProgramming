#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    if (x1 < y1) {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }

    // x1 > y1
    if (y2 >= x2) {
        std::cout << "NO";
    } else {
        std::cout << "YES";
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
