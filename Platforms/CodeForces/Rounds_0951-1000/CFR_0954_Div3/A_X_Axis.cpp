#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;

    int ans = INT_MAX;
    ans = min(ans, abs(x - y) + abs(x - z));
    ans = min(ans, abs(y - x) + abs(y - z));
    ans = min(ans, abs(z - x) + abs(z - y));

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
