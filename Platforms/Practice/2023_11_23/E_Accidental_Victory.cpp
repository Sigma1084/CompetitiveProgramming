#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    vector<bool> pos(n, true);
    ll sm = 0;
    for (int i = 0; i + 1 < n; ++i) {
        sm += a[i].first;
        if (sm < a[i + 1].first) {
            pos[i] = false;
        }
    }

    vector<int> ans;
    for (int i = n - 1; i >= 0; --i) {
        if (pos[i]) {
            ans.push_back(a[i].second);
        } else {
            break;
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto &x: ans) {
        cout << x + 1 << ' ';
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
