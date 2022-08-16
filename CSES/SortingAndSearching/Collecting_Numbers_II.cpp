#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n+2); a[0] = 0; a[n+1] = n+1;
    for (int i=1; i<=n; i++) cin >> a[i];

    vector<int> ind(n+2);
    for (int i=0; i<=n+1; i++) ind[a[i]] = i;

    int ans = 1;
    for (int i=1; i<=n; i++)
        ans += (ind[i] < ind[i-1]);

    int b, c, x, y;
    for (int _ = 0; _ < m; _++) {
        // Interchange at positions b, c
        cin >> b >> c;
        x = a[b], y = a[c];

        // Removing x and y
        if (ind[x] < ind[x-1]) ans--;
        if (ind[x+1] > ind[x]) ans++;
        if (ind[y] < ind[y-1]) ans--;
        if (ind[y+1] > ind[y]) ans++;

        cout << ans << '\n';

        // Swap
        swap(a[b], a[c]);
        ind[a[b]] = b, ind[a[c]] = c;

        // Adding x and y
        if (ind[x] < ind[x-1]) ans++;
        if (ind[x+1] > ind[x]) ans--;
        if (ind[y] < ind[y-1]) ans++;
        if (ind[y+1] > ind[y]) ans--;

        cout << ans << '\n' << '\n';
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

