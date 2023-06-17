#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &i: a) cin >> i;
    vector<int> b = a; sort(b.begin(), b.end());

    if (n%2 == 1 and b[0] != a[0]) {
        cout << "NO";
        return;
    }

    /**
     * 3 1 2 4
     * 4 1 3 2 -> 4 3 2
     * 4 3 1 2 -> 4 3 2
     * 
     * 1 2 4 3
     * 3 1 2 4 -> 3 2 4
     * 3 2 1 4 -> 3 2 4
     */

    for (int i=n%2; i<n; i+=2) {
        if (a[i] == b[i] and a[i+1] == b[i+1]) continue;
        if (a[i+1] == b[i] and a[i] == b[i+1]) continue;
        cout << "NO";
        return;
    }

    cout << "YES";
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
