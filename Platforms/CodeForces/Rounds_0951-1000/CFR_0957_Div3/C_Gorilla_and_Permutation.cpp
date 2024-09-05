#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);

    k = min(k, m + 1);
    for (int i = n, j = 0; i >= k; --i, ++j) {
        a[j] = i;
    }

    m = min(m, k - 1);
    // We need to look at the last m elements
    for (int i = m, j = n - 1; i >= 1; --i, --j) {
        a[j] = i;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
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
