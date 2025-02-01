#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> ls(n);
    vector<vector<int>> rs(n);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        ++ls[l];
        rs[r].push_back(l);
    }

    vector<int> dp(n);
    multiset<int> ms;  // Contain the lefts
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < ls[i]; ++j) {
            ms.insert(i);
        }
        dp[i] = ms.size();
        if (ms.size()) {
            int l = *ms.begin() - 1;
            if (l >= 0) {
                dp[i] += dp[l];
            }
        }
        if (i > 0) {
            dp[i] = max(dp[i], dp[i-1]);
        }
        for (int l: rs[i]) {
            ms.erase(ms.find(l));
        }
    }

    cout << dp[n-1];
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
