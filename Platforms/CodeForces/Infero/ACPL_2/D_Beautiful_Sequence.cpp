#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    int ans = 0;

    for (auto &[x, pos]: mp) {
        ans = max(ans, int(pos.size()));  // r = 0
        // Find the maximum achievable if we start with x
        pos.push_back(n);
        map<int, pair<int, int>> prev;  // [score, previous_j]
        for (int i = 0, j = 1; j < pos.size(); ++j) {
            i = max(i, pos[j - 1] + 1);
            for (; i < pos[j]; ++i) {
                if (prev[a[i]].second == j) continue;
                prev[a[i]].first += 1;
                prev[a[i]].second = j;
            }
        }
        for (auto [y, sp]: prev) {
            auto [score, j] = sp;
            ans = max(ans, int(score + pos.size() - 1));
        }
    }

    cout << ans;

    return 0;
}
