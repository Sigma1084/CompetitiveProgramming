#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x, n;
    cin >> x >> n;

    vector<int> cnt(10);
    for (int y = 1, i = 0; i < 10; ++i, y *= 10) {
        int d = x / y % 10;
        cnt[i] = d;
    }

    int k = accumulate(cnt.begin(), cnt.end(), 0);

    for (int i = 0; k < n; ) {
        if (i and cnt[i]) {
            // Send it to i - 1
            cnt[i]--;
            k += 9;
            cnt[i-1] += 10;
            --i;
        } else {
            ++i;
        }
    }

    vector<int> a(n);
    for (int i = 0, idx = 0, d = 1; i < 10; ++i, d *= 10) {
        for (int j = 0; j < cnt[i]; ++j) {
            a[min(n - 1, idx++)] += d;
        }
    }

    for (int y: a) {
        cout << y << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
