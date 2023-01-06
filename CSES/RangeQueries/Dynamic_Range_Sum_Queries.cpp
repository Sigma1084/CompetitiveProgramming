#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

// sz of the Segment Tree
int sz;
vector<ll> sg;
ll queryAns;

void update(int i, int val) {
    for (i = i+sz; i > 0; i /= 2) {
        sg[i] += val;
    }
}

void query(int node, int start, int end, int l, int r) {
    // Check for l to r in start to end
    if (r < start or l > end) return;
    if (l <= start and end <= r) { queryAns += sg[node]; return; }
    int mid = (start + end) / 2;
    query(2*node, start, mid, l, r);
    query(2*node+1, mid+1, end, l, r);
}

ll query(int l, int r) {
    queryAns = 0;
    query(1, 0, sz-1, l, r);
    return queryAns;
}

void solve() {
    int n, nQ; cin >> n >> nQ;

    sz = pow(2, (int)log2(n));
    if (sz != n) sz *= 2;
    sg.resize(2 * sz, 0);

    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        update(i, temp);
    }

    // for (int i = 1; i < 2*sz; i++) cout << sg[i] << ' ';

    for (int i = 0; i < nQ; i++) {
        int qT; cin >> qT;
        if (qT == 1) {
            int k, u; cin >> k >> u;
            update(k-1, -sg[sz+k-1]);
            update(k-1, u);
        } else if (qT == 2) {
            int a, b; cin >> a >> b;
            cout << query(a-1, b-1) << '\n';
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

