#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;

    vector<int> v;
    int s = 0, e;
    int numS = 0;
    while (s < n) {
        if (s == n-1 or a[s+1] == a[s]) {
            v.push_back(a[s]);
            s++, numS++;
        } else {
            e = s+1; while (e < n and a[e] != a[e-1]) e++;
            v.push_back(a[s]);
            if (a[s] != a[e-1]) v.push_back(a[e-1]);
            numS++;
            s = e;
        }
    }
    
    map<int, int> f; for (auto &x: v) f[x]++;
    int mF = 0; for (auto &p: f) if (p.second > mF) mF = p.second;

    // for (auto &p: v) cout << p << ' '; cout << '\n';

    // cout << mF << '\n';

    if (mF <= ((v.size() + 1) / 2)) {
        cout << numS - 1;
    } else {
        cout << -1;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }

    return 0;
}
