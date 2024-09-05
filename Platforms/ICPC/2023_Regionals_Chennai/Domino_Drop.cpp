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

    int ans = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        if (cur < i) {
            ans = i;
        }
        cur = max(cur, i + a[i] - 1);
        cout << max(0, ans + 1 - a[0]) << ' ';
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
