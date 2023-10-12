#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<vector<array<int, 2>>> e(n);

    for (int &x: a) cin >> x;
    for (int i = 1, p, c; i < n; i++) {
        cin >> p >> c;
        p--;
        e[p].push_back({i, c});
    }

    int ans = 0;

    function<void(int)> rem = [&](int u) {
        ans += 1;
        for (auto [v, c]: e[u]) {
            rem(v);
        }
    };

    function<void(int, ll, ll)> dfs = [&](int u, ll cur, ll min1Anc) {
        if (cur - min1Anc > a[u]) {
            rem(u);
            return;
        }

        for (auto [v, c]: e[u]) {
            dfs(v, cur + c, min(min1Anc, cur));
        }
    };

    dfs(0, 0, 0);
    cout << ans << endl;

    return 0;
}
