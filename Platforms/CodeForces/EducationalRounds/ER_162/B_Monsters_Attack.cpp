#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<int> b(n + 1);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        b[abs(x)] += a[i];
    }

    ll cur = 0;
    for (int i = 0; i <= n; ++i) {
        if (b[i] > cur) {
            cout << "NO";
            return;
        }
        cur += k - b[i];
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
