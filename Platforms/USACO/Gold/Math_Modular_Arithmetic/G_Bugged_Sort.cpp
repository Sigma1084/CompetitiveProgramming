#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (auto &[x, y] : a) {
        cin >> x;
    }
    for (auto &[x, y] : a) {
        cin >> y;
    }
    sort(a.begin(), a.end());

    for (int i = 0; i + 1 < n; ++i) {
        if (a[i][1] > a[i + 1][1]) {
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

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
