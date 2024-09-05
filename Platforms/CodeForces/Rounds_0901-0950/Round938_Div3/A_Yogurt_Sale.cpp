#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    
    b = min(b, a * 2);
    cout << (n / 2) * b + (n % 2) * a;
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
