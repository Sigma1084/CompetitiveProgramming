#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    map<array<int, 2>, int> f12, f23, f13;
    map<array<int, 3>, int> f;

    ll ans = 0;
    for (int i = 0; i + 2 < n; ++i) {
        ans += f12[{a[i], a[i + 1]}];
        ans += f23[{a[i + 1], a[i + 2]}];
        ans += f13[{a[i], a[i + 2]}];
        ans -= 3 * f[{a[i], a[i + 1], a[i + 2]}];
        f12[{a[i], a[i + 1]}]++;
        f23[{a[i + 1], a[i + 2]}]++;
        f13[{a[i], a[i + 2]}]++;
        f[{a[i], a[i + 1], a[i + 2]}]++;
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
