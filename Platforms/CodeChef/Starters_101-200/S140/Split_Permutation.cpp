#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    if (n % 2) {
        a.back() = n;
        --n;
    }

    for (int i = 0; i < n; i += 2) {
        a[i] = i + 1;
        a[i + 1] = n - i;
    }

    for (auto x: a) {
        cout << x << ' ';
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
