#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    string s, t;
    cin >> s >> t;

    for (int i = 0, j = 1; i < n; ++i) {
        if (s[i] == t[i]) continue;
        j = max(j, i + 1);
        while (j < n and s[j] == s[j-1]) {
           ++j;
        }
        if (j < n and s[i] + 1 == t[i] and s[j] == t[i]) {
            swap(s[i], s[j]);
        } else {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
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
