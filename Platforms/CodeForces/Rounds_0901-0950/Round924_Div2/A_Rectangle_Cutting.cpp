#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);

    // a <= b
    if (a % 2 == 0) {
        cout << "Yes";
    } else if (b % 2 == 1) {
        cout << "No";
    } else if (b/2 != a) {
        cout << "Yes";
    } else {
        cout << "No";
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
