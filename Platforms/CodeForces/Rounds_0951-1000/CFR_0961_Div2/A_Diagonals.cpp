#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k == 0) {
        cout << 0;
        return;
    }

    int ans = 1;
    k -= n;
    for (int i = n - 1; i >= 0 and k > 0; --i) {
        ans += 1;
        k -= i;
        if (k > 0) {
            ans += 1;
            k -= i;
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
