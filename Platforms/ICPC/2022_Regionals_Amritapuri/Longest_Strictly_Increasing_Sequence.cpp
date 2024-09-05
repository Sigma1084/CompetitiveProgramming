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

    if (a[0] != 1) {
        cout << "No";
        return;
    }

    for (int i = 1; i < n; ++i) {
        int d = a[i] - a[i-1];
        if (d != 0 and d != 1) {
            cout << "No";
            return;
        }
    }

    cout << "Yes\n";
    for (auto x: a) {
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
