#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    cerr << n << '\n';

    if (n % 2 == 0) {
        int i = 0;
        cout << "YES\n";
        while (n) {
            cout << string(2, 'A' + i);
            i ^= 1;
            n -= 2;
        }
    } else {
        cout << "NO";
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
