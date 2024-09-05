#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    vector<int> a(3);
    for (auto &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    if (a[0] == a[1]) {
        cout << a[2];
    } else {
        cout << a[0];
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
