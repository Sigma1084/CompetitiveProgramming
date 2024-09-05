#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b;
    cin >> a >> b;

    int xk, yk, xq, yq;
    cin >> xk >> yk >> xq >> yq;

    auto f = [&](int x, int y) {
        set<pair<int, int>> ans;
        for (int i: {-a, a}) {
            for (int j: {-b, b}) {
                ans.emplace(x + i, y + j);
                ans.emplace(x + j, y + i);
            }
        }
        return ans;
    };

    auto k = f(xk, yk), q = f(xq, yq);
    int ans = 0;
    for (auto p: k) {
        if (q.count(p)) {
            ++ans;
        }
    }

    cout << ans;
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
