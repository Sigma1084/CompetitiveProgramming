#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> eL(m);
    vector<vector<array<int, 2>>> e(n);
    for (auto &[u, v, w] : eL) {
        cin >> u >> v >> w;
        --u, --v;
        e[u].push_back({v, w});
    }

    sort(eL.begin(), eL.end(), [](auto &a, auto &b) {
        return a[2] < b[2];
    });

    
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
