#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<vector<int>, bool> f(const vector<int> &a, int b) {
    vector<int> na;
    bool merge = false;
    for (auto y: a) {
        if (merge) {
            na.back() ^= y;
        } else {
            na.push_back(y);
        }
        if (y & (1 << b)) {
            merge = !merge;
        }
    }
    return {na, merge};
}

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int b = 29;
    while ((1 << b) > x) {
        auto [na, merge] = f(a, b--);
        if (merge) {
            cout << -1;
            return;
        }
        a = move(na);
    }

    int ans = 0;
    for (; b >= -1; --b) {
        // If we set this bit to 0, we will be done
        if (b == -1) {
            ans = max(ans, int(a.size()));
            break;
        }
        auto [na, merge] = f(a, b);
        if (x & (1 << b)) {
            if (not merge) {
                ans = max(ans, int(na.size()));
            }
        } else {
            if (merge) {
                break;
            }
            a = move(na);
        }
    }

    cout << (ans == 0 ? -1 : ans);
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
