#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x, y, n;
    cin >> x >> y >> n;

    vector<int> a(n);
    a.back() = y;
    for (int i = n - 2, j = 1; i >= 0; --i, ++j) {
        a[i] = a[i + 1] - j;
    }

    if (a[0] < x) {
        cout << -1;
    } else {
        a[0] = x;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
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
