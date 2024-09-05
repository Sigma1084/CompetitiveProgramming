#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a.begin(), a.end());

    vector<int> f(n);
    ll cur = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n and (cur >= a[j][0] or j <= i)) {
            cur += a[j][0];
            ++j;
        }
        f[a[i][1]] = j;
    }

    for (auto x: f) {
        cout << x - 1 << ' ';
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
