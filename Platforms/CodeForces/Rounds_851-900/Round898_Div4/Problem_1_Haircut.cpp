#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * When we make everything equal to
 * 0 => 0
 * 1 => Num pairs (x, 0) x > 0
 * 2 => Num pairs (x, 0) + Num pairs (y, 1) x > 0, y > 1
 * 
 * bad[i] = Num pairs (x, i) x > i
 * 
 * dp[0] = 0
 * dp[1] = dp[0] + bad[0]
 * dp[2] = dp[1] + bad[1]
 */

class Fenwick {
    const int n;
    vector<int> tree;
public:
    Fenwick(int n): n(n), tree(n) {}

    void add(int index, int delta) {
        for (; index < n; index |= index + 1)
            tree[index] += delta;
    }

    ll sum(int r) {
        ll res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += tree[r];
        return res;
    }

    ll sum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) cin >> x;

    Fenwick count(n + 1);
    vector<ll> bad(n + 1);
    for (int i = 0; i < n; ++i) {
        bad[a[i]] += count.sum(a[i] + 1, n);
        count.add(a[i], 1);
    }

    vector<ll> dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i] + bad[i];
    }

    for (auto x: dp) {
        cout << x << '\n';
    }

    return 0;
}
