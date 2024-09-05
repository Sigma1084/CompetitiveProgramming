#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), p(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: p) {
        cin >> x;
    }

    vector<int> dpL(n), dpR(n);
    dpL[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] - p[i] <= a[i-1]) {
            dpL[i] = dpL[i-1];
        } else {
            dpL[i] = i;
        }
    }
    dpR[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] + p[i] >= a[i+1]) {
            dpR[i] = dpR[i+1];
        } else {
            dpR[i] = i;
        }
    }

    cerr << "dpL: ";
    for (auto x: dpL) {
        cerr << x << ' ';
    }
    cerr << '\n';

    cerr << "dpR: ";
    for (auto x: dpR) {
        cerr << x << ' ';
    }
    cerr << '\n';

    for (int i = 0; i + 1 < n; ++i) {
        if (dpL[i] == 0 and dpR[i+1] == n - 1) {
            cout << "YES";
            return;
        }
    }

    if (dpR[dpR[0] + 1] == n - 1 or dpL[dpL[n-1] - 1] == 0) {
        cout << "YES";
    } else if (a[dpR[0]] + p[dpR[0]] < a[dpL[n-1]] + p[dpL[n-1]]) {
        cout << "YES";
    } else {
        cout << "NO";
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
