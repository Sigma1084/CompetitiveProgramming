#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if ((b - c) % 2 == 0) {
        cout << "1 ";
    } else {
        cout << "0 ";
    }

    if ((a - c) % 2 == 0) {
        cout << "1 ";
    } else {
        cout << "0 ";
    }

    if ((a - b) % 2 == 0) {
        cout << "1 ";
    } else {
        cout << "0 ";
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
