#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<array<int, 3>> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i;
        a[i][2] = 0;
    }
    for (auto &x: b) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Last k elements we need to use elements from b
    for (int i = n - k, j = 0; i < n; ++i, ++j) {
        if (a[i][0] <= b[j]) {
            cout << "NO";
            return;
        } else {
            a[i][2] = b[j];
        }
    }
    for (int i = 0, j = k; j < n; ++i, ++j) {
        if (a[i][0] > b[j]) {
            cout << "NO";
            return;
        } else {
            a[i][2] = b[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        b[a[i][1]] = a[i][2];
    }

    cout << "YES\n";
    for (auto x: b) {
        cout << x << ' ';
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
