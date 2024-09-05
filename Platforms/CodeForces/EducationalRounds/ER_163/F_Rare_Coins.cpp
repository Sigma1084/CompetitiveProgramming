#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, nQ;
    cin >> n >> nQ;

    vector<int> g(n), s(n);
    for (auto &x: g) {
        cin >> x;
    }
    for (auto &x: s) {
        cin >> x;
    }

    std::partial_sum(g.begin(), g.end(), g.begin());
    std::partial_sum(s.begin(), s.end(), s.begin());

    for (int l, r; nQ--; ) {
        cin >> l >> r;
        --l, --r;
        int g1 = g[r] - (l ? g[l-1] : 0), g2 = g.back() - g1;
        int s1 = s[r] - (l ? s[l-1] : 0), s2 = s.back() - s1;

        // We need g1 + s1 > g2 + s2
        // s1 - s2 > g2 - g1
        // Xs1 ~ Bin(s1, 1/2), Xs2 ~ Bin(s2, 1/2)
        // Xs1 - Xs2 ~ Bin(s1 + s2, 1/2) - s2
        // P(X > g2 - g1 + s2) where X ~ Bin(s1 + s2, 1/2)

        // We just need to 
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
