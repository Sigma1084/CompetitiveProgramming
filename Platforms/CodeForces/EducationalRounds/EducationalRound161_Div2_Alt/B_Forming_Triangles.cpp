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

    map<int, int> cnt;
    for (auto x: a) {
        ++cnt[x];
    }

    ll ans = 0;
    int pr = 0;
    for (auto [x, f]: cnt) {
        if (f >= 2) {
            ans += 1LL * f * (f - 1) / 2 * pr;
        }
        if (f >= 3) {
            ans += 1LL * f * (f - 1) * (f - 2) / 6;
        }
        pr += f;
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
