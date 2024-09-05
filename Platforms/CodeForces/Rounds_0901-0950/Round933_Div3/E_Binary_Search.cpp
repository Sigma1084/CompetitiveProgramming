#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> p(n);
    int pX;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] == x) {
            pX = i;
        }
    }

    vector<pair<int, int>> ops;

    int l = 1, r = n + 1;
    while (1 + l < r) {
        int m = (l + r) / 2;
        if (p[m-1] == x) {
            ops.emplace_back(m, r - 1);
            pX = r - 1;
        }
        if (p[m-1] <= x) {
            l = m;
        } else {
            r = m;
        }
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
