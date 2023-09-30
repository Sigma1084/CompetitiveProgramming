#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> c(n), a(n);
    for (int &x: c) cin >> x;
    for (int &x: a) {
        cin >> x;
        x--;
    }

    int ans = 0;
    vector<int> vis(n, -1);

    for (int i = 0; i < n; i++) {
        if (vis[i] != -1) continue;
        // Otherwise go all the way
        vis[i] = i;
        int j = a[i];
        while (vis[j] == -1) {
            vis[j] = i;
            j = a[j];
        }

        if (vis[j] != i) continue;

        int k = j;
        vector<int> costs;
        do {
            costs.push_back(c[k]);
            k = a[k];
        } while (k != j);

        ans += *min_element(costs.begin(), costs.end());
    }

    cout << ans;

    return 0;
}
