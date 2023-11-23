#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = int(s.size());

    vector<int> pos = {-1};
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            pos.push_back(i);
        }
    }
    pos.push_back(n);

    int ans = 0, mn = n + 1;
    for (int i = 0; i + 1 < int(pos.size()); ++i) {
        mn = min(mn, pos[i + 1] - pos[i] - 1);
        ans += pos[i + 1] - pos[i] - 1;
    }

    cout << ans - mn;
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
