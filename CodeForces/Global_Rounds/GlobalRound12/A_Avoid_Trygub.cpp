#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    sort(s.begin(), s.end());

    cout << s;
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
