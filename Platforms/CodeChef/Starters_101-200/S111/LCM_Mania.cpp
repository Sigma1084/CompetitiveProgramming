#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    /**
     * a = k, b = 1, c = 1
     * lcm(a, b) + lcm(b, c) + lcm(c, a)
     * = k + 1 + k = 2k + 1
     * 
     * If it is a power of 2, impossible
     * 4 =>
     * 1 1 1 => 3
     * 2 1 1 => 5
     */

    int p2 = 1;
    while (n % 2 == 0) {
        p2 *= 2;
        n /= 2;
    }

    if (n == 1) {
        cout << -1;
    } else {
        int a = n / 2;
        cout << a * p2 << ' ' << p2 << ' ' << p2;
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
