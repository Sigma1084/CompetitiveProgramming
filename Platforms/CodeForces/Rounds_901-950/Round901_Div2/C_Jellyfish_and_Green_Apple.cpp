#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    n %= m;
    int g = gcd(n, m);

    if (bitset<32>(m / g).count() > 1) {
        cout << -1;
    } else {
        cout << 1LL * bitset<32>(n / g).count() * m - n;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
