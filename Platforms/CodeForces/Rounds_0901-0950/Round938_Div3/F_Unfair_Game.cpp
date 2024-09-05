#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << a/2 + b/2 + c/2 + d/2 + (a & b & c & 1);
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
