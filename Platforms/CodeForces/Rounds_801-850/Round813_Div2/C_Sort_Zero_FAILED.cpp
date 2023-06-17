#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;

    set<int> z = { 0 };
    set<int> pres = { a[0] };

    for(int i = 1; i < n; i++) {
        if (z.find(a[i]) != z.end()) a[i] = 0;  // element is 0
        auto it = pres.upper_bound(a[i]);  // first illegal element
        if (it != pres.end()) {
            // Clear everything before if the current element is trash
            for (auto i = pres.begin(); i != pres.end(); i++)
                z.insert(*i);
        }
        if (z.find(a[i]) != z.end()) a[i] = 0;
        pres.insert(a[i]);

        // for (auto &x: pres) cout << x << ' '; cout << '\n';
        // for (auto &x: z) cout << x << ' '; cout << '\n';
    }
    cout << z.size() - 1;
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

