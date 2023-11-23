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

    map<pair<int, int>, int> f;
    ll ans = 0;
    for (auto x: a) {
        pair<int, int> cls = {x, x};
        while (cls.second % 2 == 0) {
            cls.first -= 1;
            cls.second /= 2;
        }
        ans += f[cls];
        f[cls] += 1;
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
