#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct T {
    array<int, 30> last1{};
    array<int, 30> first1{};
    long long val = 0;
    int size = 0;

    constexpr T() {
        last1.fill(0);
        first1.fill(1);
    }

    friend T operator+(const T &r1, const T &r2) {
        T res;
        res.size = r1.size + r2.size;
        res.val = r1.val + r2.val;
        for (int i = 0; i < 30; ++i) {
            res.val += (1LL << i) * r1.size * r2.size;
            res.val -= (1LL << i) * (r1.size - r1.last1[i]) * (r2.first1[i] - 1);
            if (r1.last1[i] != 0) {
                // We have a 1 on the left
                res.first1[i] = r1.first1[i];
            } else {
                // We have a 1 on the right or 0
                res.first1[i] = r1.size + r2.first1[i];
            }
            if (r2.last1[i] != 0) {
                // We have a 1 on the right
                res.last1[i] = r1.size + r2.last1[i];
            } else {
                // We have a 1 on the left or 0
                res.last1[i] = r1.last1[i];
            }
        }
        return res;
    }

    friend bool operator==(const T &r1, const T &r2) {
        return r1.last1 == r2.last1 and r1.first1 == r2.first1
               and r1.val == r2.val and r1.size == r2.size;
    }

    friend ostream& operator<<(ostream& os, const T& t) {
        os << "val = " << t.val << ", size = " << t.size << '\n';
        os << "first1 = ";
        for (int i = 0; i < 30; ++i) {
            os << t.first1[i] << ' ';
        }
        os << '\n';
        os << "last1 = ";
        for (int i = 0; i < 30; ++i) {
            os << t.last1[i] << ' ';
        }
        os << '\n';
        return os;
    }
};

void solve() {
    int n;
    cin >> n;

    ll k;
    cin >> k;

    vector<T> a(n);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        a[i].val = x;
        a[i].size = 1;
        for (int j = 0; j < 30; ++j) {
            if (x & (1 << j)) {
                a[i].first1[j] = 1;
                a[i].last1[j] = 1;
            } else {
                a[i].first1[j] = 2;
                a[i].last1[j] = 0;
            }
        }
    }

    T cur;
    ll ans = 0;

    vector<T> rev(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        rev[i] = a[i] + rev[i + 1];
    }

    for (int i = 0; i < n; ++i) {
        if (cur.val > k) {
            break;
        }
        int l = i, r = n - 1;
        // Find the leftmost index such that condition holds
        // Condition: (cur + seg.query(j + 1, n - 1)) must be <= k
        while (l < r) {
            int m = (l + r) / 2;
            if ((cur + rev[m + 1]).val <= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        // The leftmost index is l
        ans += n - l;
        cur = cur + a[i];
    }

    cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
