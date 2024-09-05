#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = MOD;

void solve() {
    int n1, x, y; cin >> n1 >> x >> y;
    string s1, s2; cin >> s1 >> s2;

    vector<int> a;
    for (int i = 0; i < n1; i++) {
        if (s1[i] != s2[i]) a.push_back(i);
    }

    int n = a.size();
    if (n % 2 == 1) {
        cout << -1;
        return;
    }

    ll ans = 0;

    if (n >= 4) {
        ans = 1LL * (n/2) * y;
    } else if (n == 2) {
        if (a[0] + 1 == a[1]) {
            ans = x;
            // If there is an empty spot use it if possible
            if (n != n1) {
                ans = min(ans, 2LL*y);
            }
        } else {
            ans = y;
        }
    }

    cout << ans;
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

