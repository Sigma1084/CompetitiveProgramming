#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    int r1, c1, r2, c2, r3, c3;
    cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;

    int tr, tc;
    cin >> tr >> tc;

    // Bring these to the bottom
    while (r1 > 2 and r2 > 2 and r3 > 2) {
        r1 -= 2;
        r2 -= 2;
        r3 -= 2;
    }
    while (c1 > 2 and c2 > 2 and c3 > 2) {
        c1 -= 2;
        c2 -= 2;
        c3 -= 2;
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
