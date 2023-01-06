#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, s, e; cin >> n;
    vector<pair<int, int>> a;
    for (int i=0; i<n; i++) {
        cin >> s >> e;
        a.push_back({s, 1});
        a.push_back({e, -1});
    }

    sort(a.begin(), a.end(), [] (pair<int, int> &p1, pair<int, int> &p2) {
        if (p1.first < p2.first) return true;
        else if (p1.first == p2.first and p1.second > p2.second) return true;
        return false;
    });

    int ans = 0, cur = 0;
    for (auto &p: a) {
        cur += p.second;
        ans = max(ans, cur);
    }

    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }

    return 0;
}
