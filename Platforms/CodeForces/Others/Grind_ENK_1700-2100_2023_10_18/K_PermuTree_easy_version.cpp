#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * Given a, divide it into 2 parts such that
 * their difference of sums is minimum
 */
ll maxProd(vector<int> &a) {
    // The sum will be at most 5000 over all
    vector<bool> isPos(accumulate(a.begin(), a.end(), 1));
    int n = isPos.size() - 1;
    isPos[0] = true;
    sort(a.begin(), a.end());
    for (int x: a) {
        for (int y = n; y >= x; --y) {
            isPos[y] = isPos[y] or isPos[y-x];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (isPos[i]) {
            ans = max(ans, 1LL * i * (n - i));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> e(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        e[p].push_back(i);
    }

    ll ans = 0;
    function<void(int)> dfs;
    vector<int> sz(n, 1);
    dfs = [&] (int u) {
        for (int v: e[u]) {
            dfs(v);
            sz[u] += sz[v];
        }
        vector<int> szs;
        szs.reserve(e[u].size());
        for (int v: e[u]) {
            szs.push_back(sz[v]);
        }
        ans += maxProd(szs);
    };
    dfs(0);

    cout << ans;

    return 0;
}
