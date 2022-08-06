#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i] >> b[i];
    a.push_back(0); b.push_back(0);
    
    int ans = 0;
    ans += *max_element(a.begin(), a.end());
    ans -= *min_element(a.begin(), a.end());
    ans += *max_element(b.begin(), b.end());
    ans -= *min_element(b.begin(), b.end());

    cout << 2 * ans;
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
