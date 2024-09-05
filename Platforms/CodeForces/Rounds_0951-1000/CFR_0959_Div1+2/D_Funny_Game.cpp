#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<bool> v(n);
    vector<int> occ(n);
    vector<pair<int, int>> ans;
    ans.reserve(n - 1);

    for (int t = n - 1; t > 0; --t) {
        occ.assign(t, -1);
        for (int j = 0; j < n; ++j) {
            if (v[j]) continue;
            if (occ[a[j] % t] == -1) {
                occ[a[j] % t] = j;
                continue;
            }
            ans.emplace_back(occ[a[j] % t] + 1, j + 1);
            v[j] = true;
            break;
        }
        cerr << '\n';
    }

    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    for (auto [x, y]: ans) {
        cout << x << ' ' << y << '\n';
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
;