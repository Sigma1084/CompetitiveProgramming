#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T, typename U = T>
class PrefixSum {
    std::vector<T> pref;
public:
    PrefixSum() = default;

    PrefixSum(const vector<U> &a) {
        assign(a);
    }

    void assign(const vector<U> &a) {
        pref.resize(a.size());
        pref[0] = a[0];
        for (std::size_t i = 1; i < a.size(); ++i) {
            pref[i] = pref[i - 1] + a[i];
        }
    }

    T query(int l, int r) {
        if (l == 0) {
            return pref[r];
        } else {
            return pref[r] - pref[l - 1];
        }
    }

    void debug() {
        for (auto x: pref) {
            cerr << x << ' ';
        }
        cerr << '\n';
    }
};

template<typename T, typename U = T>
class PrefixProd {
    std::vector<T> pref;
public:

    PrefixProd() = default;

    PrefixProd(const vector<U> &a) {
        assign(a);
    }

    void assign(const vector<U> &a) {
        pref.resize(a.size());
        pref[0] = a[0];
        for (std::size_t i = 1; i < a.size(); ++i) {
            pref[i] = pref[i - 1] * a[i];
        }
    }

    T query(int l, int r) {
        if (l == 0) {
            return pref[r];
        } else {
            return pref[r] / pref[l - 1];
        }
    }

    void debug() {
        for (auto x: pref) {
            cerr << x << ' ';
        }
        cerr << '\n';
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int l = 0, r = n - 1;
    while (l < r and a[l] == 1) {
        ++l;
    }
    while (l < r and a[r] == 1) {
        --r;
    }

    ll prod = 1;
    for (int i = l; i <= r; ++i) {
        prod *= a[i];
        if (prod > 5 * n) {
            cout << l + 1 << ' ' << r + 1;
            return;
        }
    }

    vector<int> b;
    for (int i = l; i <= r; ++i) {
        if (a[i] != 1) {
            b.push_back(i);
        }
    }

    PrefixSum<int> prefSum(a);
    PrefixProd<int> prefProd(a);

    // prod <= 1e6 which is at most 20 non-1 numbers
    int aL = l, aR = r, ans = static_cast<int>(prod);
    for (int j: b) {
        for (int i: b) {
            if (i > j) {
                break;
            }
            int cur = 0;
            if (i > l) {
                cur += prefSum.query(l, i - 1);
            }
            cur += prefProd.query(i, j);
            if (j < r) {
                cur += prefSum.query(j + 1, r);
            }

            if (cur > ans) {
                ans = cur;
                aL = i, aR = j;
            }
        }
    }

    cout << aL + 1 << ' ' << aR + 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
