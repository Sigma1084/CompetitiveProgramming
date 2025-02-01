#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
    }

    sort(a.begin(), a.end(), [](array<int, 2> x, array<int, 2> y) {
        return x[0] + x[1] < y[0] + y[1];
    });

    for (auto [x, y] : a) {
        cout << x << ' ' << y << ' ';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
