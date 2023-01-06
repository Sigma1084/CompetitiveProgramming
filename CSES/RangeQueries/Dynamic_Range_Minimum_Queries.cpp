#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

int sz;
vector<int> sg;
int queryAns;

void update(int i, int val) {
    i += sz;
    sg[i] = val;
    for (i /= 2; i > 0; i /= 2) {
        sg[i] = min(sg[2*i], sg[2*i+1]);
    }
}

void query(int node, int start, int end, int l, int r) {
    if (r < start or l > end) return;
    if (l <= start and end <= r) { queryAns = min(queryAns, sg[node]); return; }
    int mid = (start+end) / 2;
    query(2*node, start, mid, l, r);
    query(2*node+1, mid+1, end, l, r);
}

int query(int l, int r) {
    queryAns = MOD;
    query(1, 0, sz-1, l, r);
    return queryAns;
}

int query2(int l, int r) {
    l += sz, r += sz;
    int ans = MOD;
    while (l <= r) {
        if (l % 2 == 1) ans = min(ans, sg[l++]);
        if (r % 2 == 0) ans = min(ans, sg[r--]);
        l /= 2; r /= 2;
    }
    return ans;
}

// Both query and query2 work like expected

void solve() {
    int n, nQ; cin >> n >> nQ;

    sz = pow(2, (int)log2(n));
    if (sz != n) sz *= 2;
    sg.resize(2 * sz, MOD);

    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        update(i, temp);
    }

    for (int i = 0; i < nQ; i++) {
        int qT; cin >> qT;
        if (qT == 1) {
            int k, u; cin >> k >> u;
            update(k-1, u);
        } else if (qT == 2) {
            int a, b; cin >> a >> b;
            cout << query2(a-1, b-1) << '\n';
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

