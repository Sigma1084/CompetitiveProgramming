#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

int sz;
vector<ll> sg;
vector<ll> lz;
ll queryAns;

void add(int i, const int &val) {
    for (i += sz; i > 0; i /= 2) {
        sg[i] += val;
    }
}

void updateRange(int node, int start, int end, int l, int r, int val) {
    if (r < start or l > end) return;
    if (l <= start and end <= r) { lz[node] += val; return; }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);
}

void update(int a, int b, int val) {
    updateRange(1, 0, sz-1, a, b, val);
}

void propagate(int node, int start, int end) {
    if (lz[node] == 0) return;
    sg[node] += lz[node] * (end - start + 1);
    if (start != end) {
        lz[2*node] += lz[node];
        lz[2*node + 1] += lz[node];
    }
    lz[node] = 0;
}

void queryRange(int node, int start, int end, int l, int r) {
    if (r < start or l > end) return;
    propagate(node, start, end);
    if (l <= start and end <= r) { queryAns += sg[node]; return; }
    int mid = (start + end) / 2;
    queryRange(node*2, start, mid, l, r);
    queryRange(node*2 + 1, mid + 1, end, l, r);
}

ll query(int a, int b) {
    queryAns = 0;
    queryRange(1, 0, sz-1, a, b);
    return queryAns;
}

void solve() {
    int n, nQ; cin >> n >> nQ;
    sz = pow(2, ceil(log2(n)));
    sg.resize(2*sz);
    lz.resize(2*sz);

    int a, b, c, d;
    for (int i = 0; i < n; i++) {
        cin >> a;
        add(i, a);
    }

    for (int i = 0; i < nQ; i++) {
        cin >> a;
        if (a == 2) {
            cin >> b;
            cout << query(b-1, b-1) << '\n';
        } else if (a == 1) {
            cin >> b >> c >> d;
            update(b-1, c-1, d);
        }
        // for (int i = 1; i < 2*sz; i++) cout << sg[i] << ' ';
        // cout << '\n';
        // for (int i = 1; i < 2*sz; i++) cout << lz[i] << ' ';
        // cout << '\n';
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

