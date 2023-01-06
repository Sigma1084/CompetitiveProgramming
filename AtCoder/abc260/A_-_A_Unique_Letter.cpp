#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    string s; cin >> s;
    sort(s.begin(), s.end());
    if (s[0] == s[1] and s[1] == s[2]) {
        cout << -1;
    } else if (s[0] == s[1]) {
        cout << s[2];
    } else {
        cout << s[0];
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

