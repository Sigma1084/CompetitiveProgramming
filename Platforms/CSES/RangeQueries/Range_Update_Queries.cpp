#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

int sz;
vector<ll> sg;

void update(int i, ll val) {
    for (i += sz; i > 0; i /= 2)
        sg[i] += val;
}

void updateRange(int l, int r, ll val) {
    // Add val to sg[l]
    // Subtract val from sg[r+1]
    update(l, val);
    if (r+1 < sz) update(r, -val);
}

ll query(int a, int b) {
    ll ans = 0;
    for (a += sz, b += sz; a <= b; a /= 2, b /= 2) {
        if (a%2 == 1) ans += sg[a++];
        if (b%2 == 0) ans += sg[b--];
    }
    return ans;
}

void solve() {
    int n, nQ; cin >> n >> nQ;
    sz = pow(2, ceil(log2(n)));
    sg.resize(2 * sz);

    // Segment Tree Construction
    int cur, prev = 0;
    for (int i = sz; i < sz+n; i++) {
        cin >> cur;
        sg[i] = cur - prev;
        prev = cur;
    }
    for (int i = sz-1; i > 0; i--)
        sg[i] = sg[2*i] + sg[2*i + 1];

    int tp, a, b, c;
    for (int i = 0; i < nQ; i++) {
        cin >> tp;
        if (tp == 1) {
            cin >> a >> b >> c;
            updateRange(a, b, c);
        } else {
            cin >> a;
            cout << query(0, a-1) << '\n';
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
        solve(); cout << '\n';
    }
    return 0;
}

