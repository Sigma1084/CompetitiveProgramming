#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); for (auto &x: a) cin >> x;
    vector<ll> s(n+1); for (int i=0; i<n; i++) s[i+1] = s[i] + a[i];

    int x, y;
    for (int _ = 0; _ < q; _++) {
        cin >> x >> y;
        cout << s[y] - s[x-1] << '\n';
    }
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

