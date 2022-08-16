#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x: a) cin >> x;
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i=0; i<n; i++) {
        int j = i+1;
        while (j<n && a[j] == a[i]) j++;
        ans += 1;
        i = j-1;
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
