#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * Suppose it's sorted
 * construct b[i] := a[i+1] - a[i]
 * sort b
 * b = [1 4 9]
 * ans = a[0] + 4 * 1 + 3 * (4 - 1) + 2 * (9 - 4)
 */

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
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
