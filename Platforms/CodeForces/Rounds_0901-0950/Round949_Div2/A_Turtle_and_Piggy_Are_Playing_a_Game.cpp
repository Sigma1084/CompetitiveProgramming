#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int l, r;
    cin >> l >> r;
    cout << std::__lg(r);
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
