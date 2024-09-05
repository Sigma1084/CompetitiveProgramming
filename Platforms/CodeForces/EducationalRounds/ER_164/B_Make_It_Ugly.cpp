#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    if (a.front() != a.back()) {
        cout << 0;
        return;
    }

    int i = 0;
    while (i < n and a[i] == a.front()) {
        ++i;
    }
    if (i == n) {
        cout << -1;
        return;
    }

    int ans = i;
    while (i < n) {
        // a[i] != a[0]
        int j = i + 1;
        while (j < n and a[j] == a[0]) {
            ++j;
        }
        ans = min(ans, j - i - 1);
        i = j;
    }

    cout << ans;
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
