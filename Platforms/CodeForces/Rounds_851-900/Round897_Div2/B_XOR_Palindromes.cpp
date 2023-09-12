#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * We will have a minimum number of 1s required to solve it
 * We will probably also have a maximum ones
 */
void solve() {
    int n; cin >> n;
    string s; cin >> s;

    string ans(n + 1, '0');
    int req = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            req++;
        }
    }

    for (int i = req; i + req <= n; i++) {
        ans[i] = '1';
        if (n % 2 == 0) i++; 
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
