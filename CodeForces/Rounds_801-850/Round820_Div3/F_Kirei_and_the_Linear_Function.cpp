#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;


void addMod9(int &a, const int &b) {
    a = (a + b) % 9;
}

template<typename T>
struct SegmentTree {
    typedef function<void(T&, const T&)> Operation_t;
    vector<T> tree;
    int n;
    const T init;
    const Operation_t operation;
    SegmentTree(int n, T init, Operation_t operation): 
        n(n), init(init), operation(operation) {
        /**
         * @brief Default Constructor
         * @param n: Number of elements of the array
         */
        this->n = pow(2, ceil(log2(n)));
        tree.resize(2 * this->n, init);
    }
    void update(int i, const T &v) {
        /**
         * @brief a[i] += v (i is ZERO INDEXED)
         * @param i Index
         * @param v Value
         */
        for (int temp = this->n + i; temp >= 1; temp /= 2) 
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
    string s; cin >> s;
    int n = s.size();

    SegmentTree<int> sg(n, 0, addMod9);
    // qeury(i, j) will give sum of elements in [i, j]
    for (int i = sg.n; i < sg.n + n; i++) {
        sg.tree[i] = s[i-sg.n] - '0';
    }

    for (int i = sg.n - 1; i > 0; i--) {
        sg.operation(sg.tree[i], sg.tree[2*i] + sg.tree[2*i+1]);
    }


    int w, m; cin >> w >> m;
    int l, r, k;

    vector<int> L(9, -1);
    vector<int> L2(9, -1);
    for (int i = 0; i+w-1 < n; i++) {
        int v = sg.query(i, i+w-1);
        if (L[v] == -1) L[v] = i;
        else if (L2[v] == -1) L2[v] = i;
    }

    pair<int, int> dp[9][9];  // dp[v][k] gives (Li, Lj) in 0 indexed
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            dp[i][j] = {-1, -1};

    for (int i = 0; i < 9; i++) {
        if (L[i] == -1) continue;
        int f = L[i];
        for (int j = 0; j < 9; j++) {
            int s;
            if (i == j) {
                if (L2[i] == -1) continue;
                else s = L2[i];
            } else if (L[j] == -1) continue;
            else s = L[j];

            for (int v = 0; v < 9; v++) {
                int k = (i*v + j) % 9;
                if (dp[v][k].first == -1 or make_pair(f+1, s+1) < dp[v][k]) {
                    dp[v][k].first = f + 1;
                    dp[v][k].second = s + 1;
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> l >> r >> k;
        // l and r are 1 indexed
        int v = sg.query(l-1, r-1);

        // Find Least (i, j) such that 
        // iv + j = k (mod 9)

        cout << dp[v][k].first << ' ' << dp[v][k].second << '\n';
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
