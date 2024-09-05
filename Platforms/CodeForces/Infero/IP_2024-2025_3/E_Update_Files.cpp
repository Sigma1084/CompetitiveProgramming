#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll s) {
    ll k = sqrt(2 * s);
    while (k*(k+1) < 2*s) k++;
    return k;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    --n;

    if (k >= 2e9 or k * (k + 1) / 2 >= n) {
        cout << f(n);
    } else {
        n -= k * (k + 1) / 2;
        cout << k + (n + k - 1) / k;
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
