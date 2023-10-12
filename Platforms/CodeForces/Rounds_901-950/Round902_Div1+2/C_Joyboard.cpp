#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    if (k > 3) {
        // No way
        cout << 0;
    } else if (k == 1) {
        // 0 is the only way
        cout << 1;
    } else if (k == 2) {
        // All the 1, ..., n-1 and the multiples of n
        cout << min(m, n - 1) + (m/n);
    } else {
        // All - the first n-1 and the multiples of n
        cout << (m - m/n) - min(m, n - 1);
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
