#include <bits/stdc++.h>
using namespace std;


/**
 * 1 1 -> 1
 * 2 3 - 1 1 -> 2
 * 3 4 -> 2 2 -> 0 1 -> 3
 * 
 */

int treat(int a, int b) {
    if (a > b) swap(a, b);
    if (a + a <= b) return (b+1)/2;
    // 2a > b
    int res = b - a;
    a -= res; // Now a = b
    res += 2*(a/3) + a%3;
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &i: a) cin >> i;
    
    int ans = INT_MAX - 2;
    for (int i=0; i<n-1; i++) {
        if (i) {
            int x = min(a[i-1], a[i+1]), y = max(a[i-1], a[i+1]);
            int res = (y - x + 1) / 2 + x;
            ans = min(ans, res);
        }
        if(i) ans = min(ans, max(a[i-1], a[i+1])); // Right and Left case
        int treatAns = treat(a[i], a[i+1]);
        // cout << treatAns << ' ';
        ans = min(ans, treatAns);
    }
    // cout << '\n';

    int l = INT_MAX, sl = INT_MAX;
    for (auto &i: a) {
        if (i < l) sl = l, l = i;
        else if (i < sl) sl = i;
    }

    ans = min(ans, (l+1)/2 + (sl+1)/2);

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
