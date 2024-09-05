#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string a, b;
    cin >> a >> b;

    int n = int(a.size());

    int i = 0;
    while (i < n and a[i] == b[i]) {
        ++i;
    }

    if (i < n) {
        if (a[i] < b[i]) {
            swap(a[i], b[i]);
        }
        ++i;
    }

    // a is greater

    while (i < n) {
        if (b[i] < a[i]) {
            swap(a[i], b[i]);
        }
        ++i;
    }

    cout << a << '\n' << b;
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
