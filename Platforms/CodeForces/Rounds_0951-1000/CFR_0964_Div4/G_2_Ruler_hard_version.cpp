#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int l = 2, r = 999;
    while (l < r) {
        int a = (2 * l + r) / 3;
        int b = (l + 2 * r) / 3;
        cout << "? " << a << ' ' << b << endl;
        int p;
        cin >> p;
        if (p == a * b) {
            l = b + 1;
        } else if (p == (a + 1) * (b + 1)) {
            r = a;
        } else if (p == a * (b + 1)) {
            l = a + 1;
            r = b;
        } else {
            assert(false);
        }
    }
    assert(l == r);

    cout << "! " << l << endl;
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
