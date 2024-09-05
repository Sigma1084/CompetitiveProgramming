#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int k, x, a;
    cin >> k >> x >> a;

    int sp = 0; // spent
    while (x--) {
        // Minimum amount to bid
        int y = (sp + 1 + k - 2) / (k - 1);
        if (a < y) {
            cout << "NO";
            return;
        }
        sp += y;
        a -= y;
    }

    cout << (1LL * a * (k - 1) > sp ? "YES" : "NO");
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
