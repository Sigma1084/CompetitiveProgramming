#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    using T = int;
    static constexpr T ID = INT_MAX;
    int n; vector<T> s;

    T f(T a, T b) { return min(a, b); }  // (any associative fn)
    SegTree(int _n) {
        n = 1 << __lg(2*_n - 1);
        s.resize(2*n, ID);
    }
    void update(int idx, T val) {
        for (s[idx += n] = val; idx /= 2; )
            s[idx] = f(s[idx * 2], s[idx * 2 + 1]);
    }
    SegTree(const vector<T> &a): SegTree(a.size()) {
        for (int i = 0; i < int(a.size()); i++)
            this->update(i, a[i]);
    }
    int query(int l, int r) {
        int rL = ID, rR = ID;  // resL and resR
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) rL = f(rL, s[l++]);
            if (r % 2 == 0) rR = f(s[r--], rR);
        }
        return f(rL, rR);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, nQ;
    cin >> n >> nQ;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    SegTree sg(a);
    int x, y;
 
    while (nQ--) {
        cin >> x >> y;
        cout << sg.query(x-1, y-1) << '\n';
    }
}
