#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;


struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int _n) {
        n = 1 << (int)ceil(log2(_n));
        tree.resize(2*n, MOD);
    }

    SegTree(const vector<int> &a) {
        n = a.size();
        n = 1 << (int)ceil(log2(n));
        tree.resize(2*n, MOD);
        for (int i = 0; i < a.size(); i++)
            this->update(i, a[i]);
    }

    void update(int i, int v) {
        for (int x = i+n; x > 0; x /= 2)
            tree[x] = min(tree[x], v);
    }

    int query(int l, int r) {
        int res = MOD;
        l += n, r += n;
        while (l <= r) {
            if (l%2 == 1) res = min(res, tree[l++]);
            if (r%2 == 0) res = min(res, tree[r--]);
            l /= 2, r /= 2;
        }
        return res;
    }
};


void solve() {
    int n, nQ; cin >> n >> nQ;
    vector<int> a(n); for (auto &x: a) cin >> x;

    SegTree sg(a);
    int x, y;   

    while (nQ--) {
        cin >> x >> y;
        cout << sg.query(x-1, y-1) << '\n';
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

