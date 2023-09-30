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
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Fenwick<ll> tree(10);
    for (int i = 0; i < 10; ++i) {
        tree.add(i, a[i]);
    }

    for (int i = 0; i < 10; ++i) {
        cout << "i = " << i << ": " << tree.sum(i) << '\n';
    }

    return 0;
}
