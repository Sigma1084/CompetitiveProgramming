#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    array<int, 3> a;
    cin >> a[0] >> a[1] >> a[2];

    for (int i = 0; i < 5; ++i) {
        *min_element(a.begin(), a.end()) += 1;
    }

    cout << a[0] * a[1] * a[2];
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
