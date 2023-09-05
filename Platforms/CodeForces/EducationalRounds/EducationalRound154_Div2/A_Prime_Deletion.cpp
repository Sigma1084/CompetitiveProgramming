#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    for (char c: s) {
        if (c == '1') {
            cout << 13;
            return;
        } else if (c == '3') {
            cout << 31;
            return;
        }
    }
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
