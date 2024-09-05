#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b + c >= 90) {
        cout << "PASS";
    } else {
        cout << "FAIL";
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