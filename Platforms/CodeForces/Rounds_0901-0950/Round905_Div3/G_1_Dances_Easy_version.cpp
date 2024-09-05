#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    assert(m == 1);

    vector<int> a(n), b(n);
    a[0] = 1;
    for (auto &x: a | views::drop(1)) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }

    ranges::sort(a);
    ranges::sort(b);

    int j = 0;
    for (int i = 0; i + j < n; ++i) {
        while (i+j < n and a[i] >= b[i+j]) {
            j++;
        }
    }

    cout << j;
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
