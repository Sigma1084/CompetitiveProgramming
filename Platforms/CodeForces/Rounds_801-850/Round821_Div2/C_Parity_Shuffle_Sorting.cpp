#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;

    vector<bool> done(n, false);
    
    int lastInd = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == a[0] % 2) lastInd = i;
    }

    cout << n-1 << '\n';

    done[lastInd] = true;

    for (int i = 0; i < lastInd; i++) {
        if (a[i] % 2 == a[0] % 2) {
            cout << i+1 << ' ' << lastInd+1 << '\n';
            done[i] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (not done[i]) {
            cout << 1 << ' ' << i+1 << '\n';
        }
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

