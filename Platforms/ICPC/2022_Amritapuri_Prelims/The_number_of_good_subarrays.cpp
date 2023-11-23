#include <bits/stdc++.h>
using namespace std;

constexpr int A = 30;

struct Range {
    // Trailing and leading 0s
    array<array<int, 2>, A> z;
    long long val = 0;
    int size = 0;

    Range() {
        z.fill({0, 0});
    };

    explicit Range(int x) {
        size = 1;
        val = x;
        z.fill({0, 0});
        for (int i = 0; i < A; ++i) {
            z[i][0] = ((x >> i) & 1) ? 0 : 1;
            z[i][1] = ((x >> i) & 1) ? 0 : 1;
        }
    }

    friend Range operator+(const Range &a, const Range &b) {
        Range res;
        res.size = a.size + b.size;
        res.val = a.val + b.val;
        for (int i = 0; i < A; ++i) {
            res.val += (1LL << i) * a.size * b.size;
            res.val -= (1LL << i) * a.z[i][1] * b.z[i][0];
            res.z[i][0] = a.z[i][0] + (a.z[i][0] == a.size) * b.z[i][0];
            res.z[i][1] = b.z[i][1] + (b.z[i][1] == b.size) * a.z[i][1];
        }
        return res;
    }

    Range& operator+=(const Range &other) {
        *this = *this + other;
        return *this;
    }
};

void solve() {
    int n;
    cin >> n;

    long long k;
    cin >> k;

    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    vector<Range> suf(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = Range(a[i]) + suf[i + 1];
    }

    long long ans = 0;
    Range pref;
    for (int i = 0, j = 0; i < n; ++i) {
        // First j such that pref + sux[j] <= k
        if (pref.val > k) {
            break;
        }
        j = max(j, i + 1);
        while (j < n and (pref + suf[j]).val > k) {
            ++j;
        }
        // j is the first index such that pref + suf[j] <= k
        ans += n - j + 1;
        pref += Range(a[i]);
    }

    cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}