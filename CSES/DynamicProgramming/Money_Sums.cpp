#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &i: a) cin >> i;
    sort(a.begin(), a.end());

    set<int> s;
    for (int i=0; i<n; i++) {
        auto sc = s;
        for(auto j=sc.begin(); j!=sc.end(); j++) s.insert(a[i] + *j);
        s.insert(a[i]);
    }

    cout << s.size() << '\n';
    for (auto &i: s) cout << i << ' ';
    cout << '\n';
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
