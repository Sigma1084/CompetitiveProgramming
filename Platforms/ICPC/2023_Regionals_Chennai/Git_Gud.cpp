#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int P = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    int g = 0, p;
    ll x;
    vector<int> ans(n + 1);
    vector<vector<pair<ll, int>>> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p >> x;
        p ^= g; x ^= g;

        v[i].reserve(v[p].size() + 1);
        v[i].emplace_back(x, 1);
        for (auto [y, f]: v[p]) {
            x = gcd(x, y);
            if (x == v[i].back().first) {
                v[i].back().second += f;
            } else {
                v[i].emplace_back(x, f);
            }
        }

        ans[i] = ans[p];
        for (auto [y, f]: v[i]) {
            ans[i] += (y % P) * f % P;
            ans[i] %= P;
        }

        cout << ans[i] << '\n';
        g = ans[i];
    }

    return 0;
}
