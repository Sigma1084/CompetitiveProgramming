#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int d = 1; d < n; ++d) {
        if (n % d) {
            continue;
        }
        for (int i = 0; i < 2; ++i) {
            int f = 0;  // fault
            for (int j = 0; j < n; ++j) {
                f += s[j] != s[(j % d) + i*d];
            }
            if (f <= 1) {
                cout << d;
                return;
            }
        }
    }

    cout << n;
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
