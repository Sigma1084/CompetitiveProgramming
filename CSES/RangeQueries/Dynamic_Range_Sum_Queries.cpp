#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct SegTree {
    int n;
    vector<ll> tree;

    SegTree(const vector<int> &a) {
        n = 1 << (int)ceil(log2(a.size()));
        tree.resize(2*n, 0ll);
        for (unsigned int i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    void add(int in, ll val) {
        // Adds val to index in
        for (int i = in + n; i > 0; i /= 2)
            tree[i] += val;
    }

    ll query(int l, int r) {
        ll res = 0;
        l += n, r += n;
        while (l <= r) {
            if (l%2 == 1) res += tree[l++];
            if (r%2 == 0) res += tree[r--];
            l /= 2, r /= 2;
        }
        return res;
    }
};

void solve() {
    int n, nQ; cin >> n >> nQ;
    vector<int> a(n); for (auto &x: a) cin >> x;

    SegTree sg(a);
    int x, y, z;
    while (nQ--) {
        cin >> x >> y >> z;
        
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

