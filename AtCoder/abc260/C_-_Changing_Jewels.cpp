#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

vector<ll> r, b;
ll x, y;

ll dpB(int);
ll dpR(int);

ll dpR(int n) {
    if (r[n] == -1)
        r[n] = dpR(n-1) + x*dpB(n);
    return r[n];
}

ll dpB(int n) {
    if (b[n] == -1)
        b[n] = dpR(n-1) + y*dpB(n-1);
    return b[n];
}

void solve() {
    r.resize(11, -1);
    b.resize(11, -1);
    r[1] = r[0] = 0;
    b[0] = 0; b[1] = 1;

    int N; cin >> N;    
    cin >> x >> y;
    
    cout << dpR(N);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

