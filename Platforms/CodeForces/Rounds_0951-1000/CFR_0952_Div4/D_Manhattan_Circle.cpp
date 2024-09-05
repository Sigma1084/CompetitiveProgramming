#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> b(n);
    for (auto &x: b) {
        cin >> x;
    }

    vector<int> rs(n), cs(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rs[i] += b[i][j] == '#';
            cs[j] += b[i][j] == '#';
        }
    }

    cout << max_element(rs.begin(), rs.end()) - rs.begin() + 1 << ' ';
    cout << max_element(cs.begin(), cs.end()) - cs.begin() + 1;
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
