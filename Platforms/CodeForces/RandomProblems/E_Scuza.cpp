#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, nQ;
    cin >> n >> nQ;

    vector<ll> a(n), mx(n);
    for (auto &x: a) {
        cin >> x;
    }
    mx[0] = a[0];
    for (int i = 1; i < n; ++i) {
        mx[i] = max(mx[i - 1], a[i]);
        a[i] += a[i - 1];
    }

    for (int i = 0, x; i < nQ; ++i) {
        cin >> x;
        // Find the last index such that mx[idx] <= x
        int idx = upper_bound(mx.begin(), mx.end(), x) - mx.begin() - 1;
        cout << (idx == -1 ? 0 : a[idx]) << ' ';
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
