#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    if (n == 3) { cout << "2 1 3"; return; }

    for (int i = 4; i < 4*(n/4) + 4; i++) {
        if (i % 2 == 0) cout << (i/2 + (int)pow(2, 20)) << ' ';
        else cout << i/2 << ' ';
    }
    n %= 4;

    if (n % 4 == 0) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) cout << (i/2 + (int)pow(2, 20)) << ' ';
            else cout << i/2 << ' ';
        }
    } else if (n % 4 == 2) {
        for (int i = 0; i < n; i++) {
            if (i == n-4) cout << (i/2 + (int)pow(2, 21)) << ' ';
            else if (i == n-2) cout << (i/2 + (int)pow(2, 21) + (int)pow(2, 20)) << ' ';
            if (i % 2 == 0) cout << (i/2 + (int)pow(2, 20)) << ' ';
            else cout << i/2 << ' ';
        }
    } else if (n % 4 == 1) {

    } else {

    }
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

