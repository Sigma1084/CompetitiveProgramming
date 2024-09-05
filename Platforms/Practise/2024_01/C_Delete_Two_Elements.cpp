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

    ll sm = accumulate(a.begin(), a.end(), 0LL) * 2;
    if (sm % n) {
        cout << 0;
        return;
    }
    sm /= n;

    map<int, int> f;
    ll ans = 0;
    for (auto x: a) {
        ans += f[sm - x];
        ++f[x];
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
