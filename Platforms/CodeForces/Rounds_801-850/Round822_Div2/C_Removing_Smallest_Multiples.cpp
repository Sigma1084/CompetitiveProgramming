#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    ll ans = 0;

    s = "0" + s; int i;
    for (i = 1; i <= n; i++) {
        // if s[i] is 1, can't remove it
        if (s[i] == '1') continue;

        // Now s[i] is already removed before or can be removed now
        for (int j = i; j <= n; j += i) {
            if (s[j] == '0') {
                s[j] = '2';
                ans += i;  // Removing j using i
            } else if (s[j] == '1') {
                // Can't remove anymore using i
                break;
            }
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

