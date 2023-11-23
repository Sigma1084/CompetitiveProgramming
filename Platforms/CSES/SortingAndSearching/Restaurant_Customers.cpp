#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> q;
    q.reserve(2 * n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        q.emplace_back(l, 0);
        q.emplace_back(r, 1);
    }
    sort(q.begin(), q.end());
    int ans = 0, cur = 0;

    for (auto [x, t]: q) {
        cur += t ? -1 : 1;
        ans = max(ans, cur);
    }

    cout << ans;

    return 0;
}
