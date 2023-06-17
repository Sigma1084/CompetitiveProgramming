#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());

    int m = n/2;
    ll ans = 0;
    for (auto &x: a) ans += abs(x - a[m]);

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

