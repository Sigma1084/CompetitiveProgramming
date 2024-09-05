#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int k;
    cin >> k;

    array<int, 30> cnt{};
    for (int i = 0, x; i < k; ++i) {
        cin >> x;
        for (int i = 0, y; i < x - 1; ++i) {
            cin >> y;
        }
        for (int i = 0; i < 30; ++i) {
            if (x & (1 << i)) {
                ++cnt[i];
            }
        }
    }

    int ans = 0;
    for (int i = 29; i >= 0; --i) {
        if (cnt[i] >= 2) {
            ans += (1 << (i + 1)) - 1;
            break;
        } else if (cnt[i] == 1) {
            ans += 1 << i;
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
