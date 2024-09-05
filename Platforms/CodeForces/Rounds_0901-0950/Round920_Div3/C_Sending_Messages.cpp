#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, f, u, t;
    cin >> n >> f >> u >> t;

    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    ll prev = 0;
    for (auto cur: a) {
        f -= min(t, u * (cur - prev));
        if (f <= 0) {
            cout << "NO";
            return;
        }
        prev = cur;
    }

    cout << "YES";
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
