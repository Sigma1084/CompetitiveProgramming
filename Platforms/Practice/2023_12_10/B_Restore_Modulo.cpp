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

    int pos = -1, neg = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i - 1]) {
            // Increasing
            if (pos == -1) {
                pos = a[i] - a[i - 1];
            } else if (a[i] - a[i - 1] != pos) {
                cout << -1;
                return;
            }
        }
        if (a[i] <= a[i - 1]) {
            // Decreasing
            if (neg == -1) {
                neg = a[i - 1] - a[i];
            } else if (a[i - 1] - a[i] != neg) {
                cout << -1;
                return;
            }
        }
    }

    if (pos == -1 or neg == -1 or pos == 0) {
        cout << 0;
    } else {
        int m = pos + neg;
        for (auto x: a) {
            if (x >= m) {
                cout << -1;
                return;
            }
        }
        cout << m << ' ' << pos;
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
