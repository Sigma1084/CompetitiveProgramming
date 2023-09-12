#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[a[i]] = i;
    }

    int ans = 0;
    for (int i = n - 1; i > 0; i--) {
        if (pos[i] < pos[i - 1]) {
            ans++;
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
