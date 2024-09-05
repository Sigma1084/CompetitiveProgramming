#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for (auto &x: a) {
        cin >> x;
        x %= m;
    }
    for (auto &x: b) {
        cin >> x;
        x %= m;
    }

    vector<int> f(m);
    for (auto x: a) {
        f[x]++;
    }

    ll ans = 0;
    for (auto x: b) {
        ans += f[(m - x) % m];
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
