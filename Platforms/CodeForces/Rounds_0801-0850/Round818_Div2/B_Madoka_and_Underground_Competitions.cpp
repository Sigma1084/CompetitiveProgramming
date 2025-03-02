#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, k, r, c;
    cin >> n >> k >> r >> c;

    int req = (r + c) % k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if((i+j) % k == req) cout << 'X';
            else cout << '.';
        }
        if (i < n) cout << '\n';
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
