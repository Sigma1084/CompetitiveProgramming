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
 * ans[0] = 0
 * ans[1] = ans[0] + bad[0]
 * ans[2] = ans[1] + bad[1]
 * ...
 */

template<typename T>
class Fenwick {
    const int n;
    vector<T> tree;
public:
    Fenwick(int n): n(n), tree(n) {}

    void add(int index, int delta) {
        for (; index < n; index |= index + 1) {
            tree[index] += delta;
        }
    }

    T sum(int r) {
        T res = 0;
        for (; r >= 0; (r &= r + 1) -= 1) {
            res += tree[r];
        }
        return res;
    }

    T sum(int l, int r) {
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

    Fenwick<int> count(n + 1);
    vector<ll> bad(n + 1);
    for (int i = 0; i < n; ++i) {
        bad[a[i]] += count.sum(a[i] + 1, n);
        count.add(a[i], 1);
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cout << ans << '\n';
        ans += bad[i];
    }

    return 0;
}
