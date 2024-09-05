#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int INF = 1e9;

void solve() {
    ll n, k1, k2;
    cin >> n >> k1 >> k2;

    if (n % 2 != k1 % 2) {
        cout << "NO";
    } else if (k1 >= INF or k2 >= INF) {
        cout << "NO";
    } else {
        ll tot = k1 * k1 + k2 * (k2 + 1);
        if (n >= tot) {
            cout << "YES";
        } else {
            cout << "NO";
        }
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
