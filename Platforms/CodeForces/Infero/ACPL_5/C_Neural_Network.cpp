#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    vector<ll> k(m);
    for (auto &x : k) {
        cin >> x;
    }

    ll g = 0;
    for (int i = 1; i < n; ++i) {
        g = gcd(g, a[i] - a[i-1]);
    }

    for (int i = 0; i < m; ++i) {
        if (g % k[i] == 0) {
            cout << "YES\n" << a[0] << " " << i + 1 << "\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
