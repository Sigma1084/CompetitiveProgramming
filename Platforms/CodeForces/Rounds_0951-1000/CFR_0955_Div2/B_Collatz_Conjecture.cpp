#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, d, k;
    cin >> n >> d >> k;

    // Calculate from 1 back to 1
    // Add 1 d - 1 times and then divide by d once so d - 1

    while (k and n > 1) {
        int m = min(k, d - (n % d));
        n += m;
        while (n % d == 0) {
            n /= d;
        }
        k -= m;
    }

    if (n == 1) {
        k %= d - 1;
        n += k;
    }

    cout << n;
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
