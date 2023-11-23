#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (auto &x: c) {
        cin >> x;
    }

    int k;
    cin >> k;

    // Index of minimum after i
    vector<int> mn(n);
    mn[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        mn[i] = mn[i + 1];
        if (c[i] < c[mn[i]]) {
            mn[i] = i;
        }
    }

    vector<int> ans(n);
    int np = k, cp = 0, nc, cc, d = k;
    for (int i = 0, j; i < n; i = j + 1) {
        j = mn[i];  // Minimum after i
        cc = c[j];
        nc = min(np, d / (cc - cp));
        d -= nc * (cc - cp);
        std::fill(ans.begin() + i, ans.begin() + j + 1, nc);
        np = nc;
        cp = cc;
    }

    for (auto x: ans) {
        cout << x << ' ';
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
