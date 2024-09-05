#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    for (int i = 2; 1; i++) {
        for (int j = 1; j < i; j++) {
            ll x, y;
            cout << "? " << j << " " << i << endl;
            cin >> x;
            cout << "? " << i << " " << j << endl;
            cin >> y;

            if (x == -1) {
                cout << "! " << i-1 << endl;
                return;
            } else if (x != y) {
                cout << "! " << x+y << endl;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); // cout << '\n';
    }
    return 0;
}

