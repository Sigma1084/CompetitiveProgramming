#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int r, c, n;
    cin >> r >> c >> n;

    string v, h;
    cin >> v >> h;

    vector<int> a, b;
    for (int i = 0; i < r; ++i) {
        if (v[i] == '#') {
            a.push_back(i);
        }
    }
    for (int i = 0; i < c; ++i) {
        if (h[i] == '#') {
            b.push_back(i);
        }
    }
    int aS = a.size(), bS = b.size();

    if (n < max(aS, bS) or n > aS * bS) {
        cout << "IMPOSSIBLE";
        return;
    }

    vector<string> g(r, string(c, '.'));
    while (aS + bS - 1 > n) {
        g[a.back()][b.back()] = '@';
        a.pop_back();
        b.pop_back();
        --aS, --bS, --n;
    }

    for (int i = 0; i < aS; ++i, --n) {
        g[a[i]][b[0]] = '@';
    }
    for (int j = 1; j < bS; ++j, --n) {
        g[a[0]][b[j]] = '@';
    }

    for (int i = 0; i < aS and n; ++i) {
        for (int j = 0; j < bS and n; ++j) {
            if (g[a[i]][b[j]] == '.') {
                g[a[i]][b[j]] = '@';
                --n;
            }
        }
    }

    cout << "POSSIBLE\n";
    for (const auto &x: g) {
        cout << x << '\n';
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
