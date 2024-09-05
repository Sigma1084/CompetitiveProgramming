#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    ll ans = a + b / 3;
    b %= 3;
    if (b and c + b < 3) {
        cout << -1;
        return;
    } else if (b) {
        ans += 1;
        c -= 3 - b;
    }

    ans += (c + 2) / 3;

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
