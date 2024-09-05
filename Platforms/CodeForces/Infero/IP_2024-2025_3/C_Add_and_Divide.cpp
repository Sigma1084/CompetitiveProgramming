#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b;
    cin >> a >> b;

    bool is1 = false;
    if (b == 1) {
        is1 = true;
        ++b;
    }

    int ans = INT_MAX;
    for (int i = 0; i <= 30; ++i) {
        int cur = i;
        int x = a;
        while (x > 0) {
            x /= b + i;
            ++cur;
        }
        ans = min(ans, cur);
    }
    ans += is1;

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
