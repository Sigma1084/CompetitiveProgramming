#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int getLcm() {
    int res = 1;
    for (int i = 2; i <= 20; ++i) {
        res = lcm(res, i);
    }
    return res;
}
constexpr int L = getLcm();

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = L / a[i];
    }

    if (accumulate(b.begin(), b.end(), 1LL) < L) {
        for (auto x: b) {
            cout << x << ' ';
        }
    } else {
        cout << -1;
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
