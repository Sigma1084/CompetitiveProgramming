#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            cout << "NO";
            return;
        }
    }

    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        ++cnt[a[i]];
    }

    for (auto [x, f]: cnt) {
        if (f > (n + 1) / 2) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
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
