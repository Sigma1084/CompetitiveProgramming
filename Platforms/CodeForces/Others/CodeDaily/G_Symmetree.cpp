#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> e(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int rep = 0;
    map<vector<int>, int> mp;
    vector<bool> isPos;  // isPos[rep] = 1 if rep is a positive representation.

    function<int(int, int)> dfs = [&](int u, int p) -> int {
        vector<int> subTypes;
        for (int v: e[u]) {
            if (v == p) continue;
            int type = dfs(v, u);
            subTypes.push_back(type);
        }
        sort(subTypes.begin(), subTypes.end());

        // Similar subtrees have the same representation.
        if (mp.find(subTypes) == mp.end()) {
            mp[subTypes] = rep++;
            isPos.push_back(false);
        } else {
            return mp[subTypes];
        }

        // Now count the subtypes
        set<int> s;
        for (int type: subTypes) {
            if (s.find(type) != s.end()) {
                s.erase(type);
            } else {
                s.insert(type);
            }
        }

        // s is empty means every child is balanced out.
        int curRep = mp[subTypes];
        if (s.empty() or (s.size() == 1 and isPos[*s.begin()])) {
            isPos[curRep] = true;
        }
        return curRep;
    };

    bool ans = isPos[dfs(0, -1)];

    if (ans) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output_sol.txt", "w", stdout);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
