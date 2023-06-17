#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

template<typename T>
struct SegmentTree {
    typedef function<void(T&, const T&)> Operation_t;
    const T init;
    const Operation_t operation;

    vector<T> tree;
    int n;

    SegmentTree(const int &_n, const T &init, const Operation_t &operation):
        n(_n), init(init), operation(operation) {
        /**
         * @brief Default Constructor
         * @param n: Number of elements of the array
         */
        n = pow(2, ceil(log2(n)));
        tree.resize(2 * n, init);
    }
    
    SegmentTree(const vector<int> &a, const T &init, const Operation_t 
        &_operation): n(a.size()), init(init), operation(_operation) {
        /**
         * @brief Constructor
         * @param a: Array of elements
         */
        n = pow(2, ceil(log2(n)));
        tree.resize(2 * n, init);
        for (int i = 0; i < a.size(); i++)
            tree[n+i] = a[i];
        for (int i = n-1; i > 0; i--)
            tree[i] = tree[2*i], operation(tree[i], tree[2*i + 1]);
    }
    
    void update(int i, const T &v) {
        /**
         * @brief a[i] += v (i is ZERO INDEXED)
         * @param i Index
         * @param v Value
         */
        for (int temp = n + i; temp; temp /= 2)
            operation(tree[temp], v);
    }
    
    int query(int l, int r) {
        /**
         * @brief Sum of elements in [l, r]
         * @param l Left index
         * @param r Right index
         * @return Sum of elements in [l, r]
         */
        T res = init;
        l += n, r += n;
        while (l <= r) {
            if (l % 2 == 1) operation(res, tree[l++]);
            if (r % 2 == 0) operation(res, tree[r--]);
            l /= 2, r /= 2;
        }
        return res;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());

    vector<int> b(n);
    for (int i = 0; i < n-k; i++)
        b[i] = a[i+k-1] - a[i];
    for (int i = n-k; i < n; i++)
        b[i] = a[n-1] - a[n-k];

    SegmentTree<int> st(b, INT_MAX, [] (int &a, const int &b) { 
        a = min(a, b);
    });

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, st.query(max(0, i-k+1), i));

    cout << ans;
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
