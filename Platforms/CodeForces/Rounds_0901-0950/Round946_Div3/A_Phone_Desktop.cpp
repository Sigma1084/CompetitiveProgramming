#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int o, t;
    cin >> o >> t;

    int ans = (t + 1) / 2;
    o -= ans * 7 + (t % 2) * 4;

    if (o > 0) {
        ans += (o + 14) / 15;
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
