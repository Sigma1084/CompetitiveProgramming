#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    if (k != 4 or n == 1) {
        int ans = k;
        for (auto x: a) {
            x %= k;
            ans = min(ans, (k - x) % k);
        }
        cout << ans;
        return;
    }

    // 2 evens done
    int evens = 0;
    for (auto x: a) {
        while (x % 2 == 0) {
            evens += 1;
            x /= 2;
        }
    }
    if (evens >= 2) {
        cout << 0;
        return;
    }

    // We have a 3 done or even and 4
    for (auto x: a) {
        if (x % 4 == 3 or (evens and x % 4 == 1)) {
            cout << 1;
            return;
        }
    }

    // We don't have a 3.
    cout << 2;

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
