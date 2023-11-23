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

    vector<int> b(n - 1);
    for (int i = 0; i + 1 < n; ++i) {
        b[i] = std::lcm(a[i], a[i + 1]);
    }

    for (int i = 0; i + 2 < n; ++i) {
        if (std::gcd(b[i], b[i+1]) != a[i+1]) {
            cout << "NO";
            return;
        }
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
