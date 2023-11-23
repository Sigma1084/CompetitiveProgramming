#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "No";
        return;
    }

    vector<pair<int, int>> a(n);
    int k = n / 2;
    for (int i = 0, cnt = 2*n - k + 1; i < n; ++i) {
        a[i] = {cnt++, 0};
    }
    int cnt = 1;
    for (int i = 0; i < n; i += 2) {
        auto &[f, s] = a[i];
        s = cnt++;
        f = f - s;
    }
    for (int i = 1; i < n; i += 2) {
        auto &[f, s] = a[i];
        s = cnt++;
        f = f - s;
    }

    cout << "Yes\n";
    for (auto [f, s]: a) {
        cout << f << ' ' << s << '\n';
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
