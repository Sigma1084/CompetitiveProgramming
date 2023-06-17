#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// 0 INDEXED
struct SegTree {
    int n;  // Number of nodes
    vector<ll> tree;  // Tree

    SegTree(int _n) {
        n = _n & -_n;
        if (n != _n) n *= 2;
        tree.resize(2 * n);
    }

    SegTree(const vector<ll> &a): SegTree(a.size()) {
        // Build the tree
        for (int i = 0; i < a.size(); i++) update(i, a[i]);
    }

    void update(int i, ll val) {
        for (i += n; i > 0; i /= 2) {
            tree[i] += val;
        }
    }

    ll query(int s, int e) {
        s += n, e += n;
        ll ans = 0;
        while (s <= e) {
            if (s % 2 == 1) ans += tree[s++];
            if (e % 2 == 0) ans += tree[e--];
            s /= 2, e /= 2;
        }
        return ans;
    }
};

void solve() {
    int n, nQ; cin >> n >> nQ;
    vector<ll> a(n); for (auto &x: a) cin >> x;

    SegTree sg(a);
    for (int _ = 0; _ < nQ; _++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1) {
            sg.update(y-1, z - a[y-1]);
            a[y-1] = z;
        } else if (x == 2) {
            cout << sg.query(y-1, z-1) << '\n';
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

