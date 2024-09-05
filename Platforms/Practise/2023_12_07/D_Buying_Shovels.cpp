#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> divs;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i) continue;
        divs.push_back(i);
        divs.push_back(n / i);
    }

    int ans = n;
    for (int d: divs) {
        if (d <= k) {
            ans = min(ans, n / d);
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
