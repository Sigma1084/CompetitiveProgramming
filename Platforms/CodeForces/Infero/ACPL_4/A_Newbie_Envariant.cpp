#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    int ans = 0;
    for (int i = l1; i <= r1; ++i) {
        if (l2 <= i and i <= r2) {
            ++ans;
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
