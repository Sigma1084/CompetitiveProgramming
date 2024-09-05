#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int h, w;
    array<int, 2> a, b;
    cin >> h >> w >> a[0] >> a[1] >> b[0] >> b[1];

    if (a[0] >= b[0]) {
        cout << "Draw";
        return;
    }

    // Intersection row
    int r = (a[0] + b[0] + 1) / 2;
    // Max left and right they can go
    int aL = a[1] - (r - a[0]), aR = a[1] + (r - a[0]);
    int bL = b[1] - (b[0] - r), bR = b[1] + (b[0] - r);
    aL = max(aL, 1), aR = min(aR, w);
    bL = max(bL, 1), bR = min(bR, w);

    if ((b[0] - a[0]) % 2) {
        // Odd: Alice can win
        if (aL <= bL and bR <= aR) {
            cout << "Alice";
        } else {
            cout << "Draw";
        }
    } else {
        // Even: Bob can win
        if (bL <= aL and aR <= bR) {
            cout << "Bob";
        } else {
            cout << "Draw";
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
