#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    int z;
    if (x == 0) {
        z = y;
    } else if (y == 0) {
        z = x;
    } else {
        cout << -1;
        return;
    }

    if (z == 0) {
        cout << -1;
        return;
    }

    if ((n-1) % z != 0) {
        cout << -1;
        return;
    }

    for (int i = 0; i < (n-1)/z; i++)
        for (int j = 0; j < z; j++)
            cout << 2 + i*z << ' ';
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

