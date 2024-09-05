#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int A = 1e9;

void solve() {
    int n, c, d;
    cin >> n >> c >> d;

    vector<int> b(n*n), a;
    for (auto &x: b) {
        cin >> x;
    }
    sort(b.begin(), b.end());

    if (b.front() + (n - 1) * (c + d) != b.back()) {
        cout << "NO";
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a.push_back(b[0] + i * c + j * d);
        }
    }
    sort(a.begin(), a.end());

    if (a == b) {
        cout << "YES";
    } else {
        cout << "NO";
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
