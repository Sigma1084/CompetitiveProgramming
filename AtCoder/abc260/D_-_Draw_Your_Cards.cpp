#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto &x: a) cin >> x;

    vector<vector<int>> vs;
    set<int> s;
    vector<int> m(n+1, -1);
    vector<int> ans(n+1, -1);

    for (int mo = 1; mo <= n; mo++) {
        int i = a[mo-1];
        if (s.empty() or i > *s.rbegin()) {
            s.insert(i);
            vs.push_back({i});
            m[i] = vs.size()-1;
        } else {
            int j = *s.upper_bound(i);
            m[i] = m[j];
            vs[m[i]].push_back(i);
            s.erase(j);
            s.insert(i);
        }
        if (vs[m[i]].size() == k) {
            for (auto &j: vs[m[i]])
                ans[j] = mo;
            s.erase(i);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    
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

