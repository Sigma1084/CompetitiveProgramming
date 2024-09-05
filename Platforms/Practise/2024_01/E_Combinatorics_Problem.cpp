#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int P = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, a1, x, y, m, k;
    cin >> n >> a1 >> x >> y >> m >> k;

    vector<int> a(n);
    a[0] = a1;
    for (int i = 1; i < n; ++i) {
        a[i] = (1LL * a[i-1] * x + y) % m;
    }

    for (int j = 0; j <= k; ++j) {
        for (int i = 1; i < n; ++i) {
            a[i] += a[i-1];
            if (a[i] >= P) {
                a[i] -= P;
            }
        }
    }

    ll ans = 0;
    for (int i = k; i + (k == 0) <= n; ++i) {
        ans ^= 1LL * i * a[i - k];
    }

    cout << ans << '\n';

    return 0;
}
