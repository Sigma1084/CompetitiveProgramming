#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    array<array<int, 2>, 4> a;
    for (auto &p : a) {
        cin >> p[0] >> p[1];
    }
    sort(a.begin(), a.end());

    int area = (a[2][0] - a[1][0]) * (a[1][1] - a[0][1]);
    cout << area;
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
