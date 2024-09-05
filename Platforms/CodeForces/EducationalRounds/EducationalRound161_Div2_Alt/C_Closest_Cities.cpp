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

    vector<ll> dpL(n);
    dpL[1] = 1;
    for (int i = 2; i < n; ++i) {
        // Reach i from 0
        if (abs(a[i-1] - a[i]) < abs(a[i-1] - a[i-2])) {
            dpL[i] = dpL[i-1] + 1;
        } else {
            dpL[i] = dpL[i-1] + abs(a[i-1] - a[i]);
        }
    }

    vector<ll> dpR(n);
    dpR[n-2] = 1;
    for (int i = n - 3; i >= 0; --i) {
        // Reach i from n - 1
        if (abs(a[i+1] - a[i]) < abs(a[i+1] - a[i+2])) {
            dpR[i] = dpR[i+1] + 1;
        } else {
            dpR[i] = dpR[i+1] + abs(a[i+1] - a[i]);
        }
    }

    int nQ;
    cin >> nQ;

    while (nQ--) {
        int l, r;
        cin >> l >> r;
        --l, --r;

        if (l < r) {
            // Left to right, use dpL
            cout << dpL[r] - dpL[l] << '\n';
        } else {
            // Right to left, use dpR
            swap(l, r);
            cout << dpR[l] - dpR[r] << '\n';
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
