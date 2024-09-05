#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int i = 0, j = n - 1;
    while (k and i <= j) {
        if (k == 1) {
            a[i] -= 1;
            if (a[i] == 0) {
                ++i;
            }
            break;
        }
        if (i == j) {
            a[i] -= min(a[i], k);
            if (a[i] == 0) {
                ++i;
            }
            break;
        }
        int v = min({a[i], a[j], k/2});
        a[i] -= v;
        a[j] -= v;
        k -= 2 * v;
        if (a[i] == 0) {
            ++i;
        }
        if (a[j] == 0) {
            --j;
        }
    }

    cout << n - (j - i + 1);
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
