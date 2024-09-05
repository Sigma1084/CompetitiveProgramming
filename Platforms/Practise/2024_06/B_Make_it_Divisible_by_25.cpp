#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;

    bool f = false, z = false;
    int ans = 0;
    for (; n; ++ans) {
        int d = n % 10;
        n /= 10;
        if (z) {
            if (d == 5 or d == 0) {
                break;
            }
        } else if (d == 0) {
            z = true;
        }
        if (f) {
            if (d == 2 or d == 7) {
                break;
            }
        } else if (d == 5) {
            f = true;
        }
    }

    cout << ans - 1;
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
