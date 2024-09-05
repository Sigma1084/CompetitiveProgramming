#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    array<string, 21> a;
    for (auto &x: a) {
        cin >> x;
    }

    constexpr int n = 21;

    int ans = 0;
    for (int i = 0; i + 3 < n; ++i) {
        for (int j = 0; j + 3 < n; ++j) {
            int cur = 0;
            for (int di = 0; di < 4; ++di) {
                for (int dj = 0; dj < 4; ++dj) {
                    if (a[i + di][j + dj] == '1') {
                        ++cur;
                    }
                }
            }
            ans = max(ans, cur);
        }
    }
    cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
