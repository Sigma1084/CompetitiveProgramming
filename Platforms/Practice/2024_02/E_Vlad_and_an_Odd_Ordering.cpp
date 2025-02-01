#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    int m = 1;
    while (true) {
        int t = (n + 1) / 2;
        if (k <= t) {
            cout << m * (2*k - 1);
            return;
        }
        k -= t;
        n /= 2;
        m *= 2;
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
