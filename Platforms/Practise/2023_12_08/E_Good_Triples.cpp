#include <bits/stdc++.h>
using namespace std;
using ll = long long;

std::array<ll, 10> precompute() {
    std::array<ll, 10> res;
    res[0] = 1;
    for (int i = 1; i < 10; ++i) {
        res[i] = res[i-1] * (i + 2) / i;
    }
    return res;
}

const auto dp = precompute();

void solve() {
    int n;
    cin >> n;

    ll ans = 1;
    while (n) {
        ans *= dp[n % 10];
        n /= 10;
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
