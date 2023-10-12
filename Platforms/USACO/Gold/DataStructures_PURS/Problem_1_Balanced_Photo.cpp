#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    // Set a[i] = rank(a[i])
    vector<array<int, 2>> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = {a[i], i};
    }
    sort(b.begin(), b.end());
    a[b[0][1]] = 0;
    for (int i = 1; i < n; ++i) {
        a[b[i][1]] = a[b[i-1][1]] + (b[i][0] != b[i-1][0]);
    }

    Fenwick<int> bef(n + 1), aft(n + 1);
    for (int i = 0; i < n; ++i) {
        aft.add(a[i], 1);
    }

    int ans = 0;
    for (int i = 0, l, r; i < n; ++i) {
        aft.add(a[i], -1);
        l = bef.sum(a[i] + 1, n);
        r = aft.sum(a[i] + 1, n);
        ans += max(l, r) > 2 * min(l, r);
        bef.add(a[i], 1);
    }

    cout << ans;

    return 0;
}
