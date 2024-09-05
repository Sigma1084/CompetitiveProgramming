#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();
    int ans = m;
    for (int i = 0; i < m; ++i) {
        // Check the maximum contained thing in a
        int j = i;
        for (int k = 0; k < n and j < m; ++k) {
            if (a[k] == b[j]) {
                ++j;
            }
        }
        ans = min(ans, i + m - j);
    }

    cout << ans + n;
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
