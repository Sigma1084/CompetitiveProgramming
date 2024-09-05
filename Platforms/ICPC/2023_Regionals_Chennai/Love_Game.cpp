#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll s, m;
    cin >> s >> m;
    int ans = 0;

    while (ans < 1000 and s <= m) {
        ++ans;
        s = s*s - 1;
    }

    if (ans == 1000) {
        cout << "TRY SOMETHING ELSE";
    } else {
        cout << ans;
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
