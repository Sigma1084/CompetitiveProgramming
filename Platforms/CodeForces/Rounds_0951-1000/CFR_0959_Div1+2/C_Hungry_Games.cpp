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

    vector<int> f(n);
    for (int i = 0, j = 0, s = 0; i < n; ++i) {
        while (j < n and s + a[j] <= k) {
            s += a[j++];
        }
        f[i] = j;
        s -= a[i];
    }

    vector<int> g(n);
    for (int i = n - 1; i >= 0; --i) {
        g[i] = f[i] - i;
        if (f[i] + 1 < n) {
            g[i] += g[f[i] + 1];
        }
    }

    cout << accumulate(g.begin(), g.end(), 0LL);
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
