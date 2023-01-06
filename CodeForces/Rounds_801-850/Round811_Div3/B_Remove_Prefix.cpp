#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;

    int ans = 1; set<int> s; s.insert(a[n-1]);
    for (int i=n-2; i>=0; i--, ans++) {
        int x = s.size();
        s.insert(a[i]);
        int y = s.size();
        // cout << "x: " << x;
        // cout << " " << a[i];
        // cout << " y: " << y << '\n';
        if (x == y) break;
    }

    cout << n - ans;
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

