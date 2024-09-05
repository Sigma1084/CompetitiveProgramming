#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * Initially it was xk
 * For k to be a local maxima,
 * (d + x)(k - 1) = xk + dk - (x + d)
 * xk > xk + d(k - 1) - x
 * x > d1(k - 1) works
 * x + d1 > d2(k - 2)
 */

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
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
