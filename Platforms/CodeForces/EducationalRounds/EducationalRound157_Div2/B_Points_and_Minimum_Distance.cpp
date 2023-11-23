#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(2 * n);
    for (auto &x: a) {
        cin >> x;
    }

    sort(a.begin(), a.end());

    cout << a[n - 1] - a[0] + a[2*n - 1] - a[n] << '\n';
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ' << a[n + i] << '\n';
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
