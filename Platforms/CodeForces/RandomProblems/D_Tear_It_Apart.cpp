#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = int(s.size());

    vector<vector<int>> pos(26, vector<int>(1));
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].push_back(i + 1);
    }

    int ans = INT_MAX;
    for (auto &v: pos) {
        v.push_back(n + 1);
        int mx = 0;
        for (int i = 1; i < int(v.size()); ++i) {
            int t = v[i] - v[i - 1] - 1;
            if (t == 0) continue;
            mx = max(mx, 1 + std::__lg(t));
        }
        ans = min(ans, mx);
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
