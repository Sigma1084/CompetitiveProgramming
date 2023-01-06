#include <bits/stdc++.h>
using namespace std;


/**
 * @brief Segment Tree Class
 * 
 * Rooted at 1
 * Left Child is 2*n and Right Child is 2*n + 1
 */
template<typename T>
struct SegmentTree {
    typedef function<void(T&, const T&)> Operation_t;
    const T init;
    const Operation_t operation;

    vector<T> tree;
    int n;

    /**
     * @brief Construct a new Segment Tree object
     * @param _n Number of elements
     * @param init Inital Value
     * @param operation Operation
     */
    SegmentTree(const int &_n, const T &init, const Operation_t &operation):
        n(_n), init(init), operation(operation) {
        n = pow(2, ceil(log2(n)));
        tree.resize(2 * n, init);
    }

    /**
     * @brief Construct a new Segment Tree object using an array
     * @param a Array
     * @param init Initial Value
     * @param operation Operation
     */
    SegmentTree(const vector<int> &a, const T &init, const Operation_t 
        &operation): n(a.size()), init(init), operation(operation) {
        n = pow(2, ceil(log2(n)));
        tree.resize(2 * n, init);
        for (int i = 0; i < a.size(); i++)
            tree[n+i] = a[i];
        for (int i = n-1; i > 0; i--)
            tree[i] = tree[2*i], operation(tree[i], tree[2*i + 1]);
    }

    /**
     * @brief Operation(a[i], v) (i is ZERO INDEXED)
     * @param i Index
     * @param v Value
     */
    void update(int i, const T &v) {
        for (int temp = n + i; temp; temp /= 2)
            operation(tree[temp], v);
    }

    /**
     * @brief Operations of elements in [l, r] 0 indexed
     * @param l Left index
     * @param r Right index
     * @return Operations of elements in [l, r]
     */
    int query(int l, int r) {
        T res = init;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) operation(res, tree[l++]);
            if (r % 2 == 0) operation(res, tree[r--]);
        }
        return res;
    }
};

/* Segment Or with initial value = 0 */
void seg_or(int &a, const int &b) { 
    a = a | b;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n); for (int &i: a) cin >> i;

        SegmentTree<int> sg(a, 0, seg_or);
        int allOr = sg.query(0, n-1);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            // Assume subarray starts from i
            int before = sg.query(0, i-1);
            int arrOr, after;

            // Use Binary Search to find max_j
            int l = i, r = n-1, m;

            if (before == allOr) {
                r = n-1;
                if (sg.query(i+1, r) == allOr)
                    ans = max(ans, r - i + 1);
                continue;
            }

            while (l <= r) {
                m = (l + r) / 2;
                arrOr = sg.query(i, m);
                after = sg.query(m+1, n-1);

                if (allOr == arrOr) {
                    if ((before|after) == allOr) {
                        ans = max(ans, m - i + 1);
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                } else {
                    l = m + 1;
                }
            }
        }

        if (ans == 0) {
            cout << -1;
        } else {
            cout << ans;
        }
        cout << '\n';
    }
	return 0;
}
