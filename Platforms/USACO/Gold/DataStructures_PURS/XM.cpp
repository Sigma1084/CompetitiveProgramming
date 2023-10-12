#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

struct SegmentTree {

    int n;
    vector<int>st;

    SegmentTree() {}
    SegmentTree(int n) {
        this->n = n;
        st.resize(5 * n, 0);
    }
    int query(int start, int ending, int node, int l , int r) {
        if (start > r || ending < l) return 0;
        if (start >= l && ending <= r) return st[node];
        int mid = (start + ending) / 2;
        return query(start, mid, 2 * node + 1, l, r) + query(mid + 1, ending, 2 * node + 2, l , r);
    }
    void update(int start, int ending, int node, int index, int val) {
        if (start == ending) {
            st[node] += val;
            return;
        }
        int mid = (start + ending) / 2;
        if (index <= mid) update(start, mid, 2 * node + 1, index, val);
        else update(mid + 1, ending, 2 * node + 2, index, val);
        st[node] = st[2 * node + 1]  + st[2 * node + 2] ;
    }
};


signed main() {
#ifndef ONLINE_JUDGE
    // freopen("bphoto.in", "r" , stdin);
    // freopen("bphoto.out", "w", stdout);
#endif
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r" , stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int n; cin >> n;
    vector<int>arr(n);
    vector<int>A;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        A.push_back(arr[i]);
    }
    sort(A.begin(), A.end());
    int m = lower_bound(A.begin(), A.end(), A[A.size() - 1]) + 1 - A.begin();
    SegmentTree treel(m), treer(m);
    vector<int>l(n), r(n);
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(A.begin(), A.end(), arr[i]) - A.begin();
        l[i] = treel.query(0, m - 1, 0, idx + 1, m);
        treel.update(0, m - 1, 0, idx, 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        int idx = lower_bound(A.begin(), A.end(), arr[i]) - A.begin();
        r[i] = treer.query(0, m - 1, 0, idx + 1, m);
        treer.update(0, m - 1, 0, idx, 1);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cerr << i << ": " << l[i] << " " << r[i] << endl;
        if (l[i] == 0 && r[i] == 0) continue;
        else if (l[i] == 0 || r[i] == 0) cnt++;
        else if ( 2 * min(l[i], r[i]) < max(l[i], r[i])) cnt++;
    }
    cout << cnt << endl;

    return 0;

}
