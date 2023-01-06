#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string a, b;
    cin >> a >> b;

    for (auto &c: a) if (c == 'G') c = 'B';
    for (auto &c: b) if (c == 'G') c = 'B';

    if (a == b) cout << "YES";
    else cout << "NO";
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

