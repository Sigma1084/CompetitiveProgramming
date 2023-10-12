#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll ans;
    if (n == 5) {
        ans = max(a[4] + a[2] - a[1] - a[0], a[4] + a[3] - a[2] - a[0]);
    } else {
        ans = a[n-1] + a[n-2] - a[0] - a[1];
    }

    cout << ans / 2;
    if (ans % 2) {
        cout << ".5";
    } else {
        cout << ".0";
    }
    cout << "000000000";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("here_comes_santa_claus_input.txt", "r", stdin);
    freopen("here_comes_santa_claus_output.txt", "w", stdout);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }

    return 0;
}

