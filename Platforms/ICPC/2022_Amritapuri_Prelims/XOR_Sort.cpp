#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a.begin(), a.end());

    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[a[i][1]] = i;
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        if (pos[i] == i) {
            continue;
        }
        int j = pos[i];
        swap(a[i][1], a[j][1]);
        swap(pos[a[i][1]], pos[a[j][1]]);
        ans.emplace_back(a[i][1], a[j][1]);
        ans.emplace_back(a[j][1], a[i][1]);
        ans.emplace_back(a[i][1], a[j][1]);
    }

    cout << ans.size() << '\n';
    for (auto [x, y]: ans) {
        cout << x + 1 << ' ' << y + 1 << '\n';
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

// 01:43:09