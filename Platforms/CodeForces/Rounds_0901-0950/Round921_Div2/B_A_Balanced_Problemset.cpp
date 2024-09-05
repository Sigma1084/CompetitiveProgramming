#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * Suppose gcd g is possible
 * Then, we will do a g g g g g ... g g kg
 * where k >= 1
 * So, (n - 1 + k) <= s / g
 * If s/g >= n, we are done
 */
void solve() {
    int s, n;
    cin >> s >> n;

    int ans = 1;
    for (int g = 1; g * g <= s; ++g) {
        if (s % g) continue;
        if (s / g >= n) ans = max(ans, g);
        if (g >= n) ans = max(ans, s / g);
    }

    cout << ans;
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
