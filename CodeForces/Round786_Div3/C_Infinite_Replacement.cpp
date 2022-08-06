#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t; cin >> s >> t;
    int n = s.size();
    if (t == "a") {
        cout << 1; return;
    }
    for (char &c: t) if (c == 'a') {
        cout << -1; return;
    }
    cout << (long long) pow(2, n);
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
