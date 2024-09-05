#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    int ans = 0, val = 0;
    for (int x = 2; x <= n; ++x) {
        int m = n / x;
        if (x * m * (m + 1) / 2 > val) {
            ans = x;
            val = x * m * (m + 1) / 2;
        }
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
