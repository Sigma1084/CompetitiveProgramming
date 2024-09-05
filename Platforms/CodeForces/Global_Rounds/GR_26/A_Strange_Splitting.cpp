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

    if (a.front() == a.back()) {
        cout << "NO";
        return;
    }

    cout << "YES\n";
    if (a[1] != a.back()) {
        cout << 'R' + string(n - 1, 'B');
    } else {
        cout << string(n - 1, 'R') + 'B';
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
