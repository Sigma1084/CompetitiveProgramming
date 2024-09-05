#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll avg = accumulate(a.begin(), a.end(), 0LL);
    if (avg % n) {
        cout << "No";
        return;
    } else {
        avg /= n;
    }

    array<int, 31> cnt;
    cnt.fill(0);

    for (int i = 0, x, r, s; i < n; i++) {
        x = abs(a[i] - avg);
        if (x == 0) continue;

        r = x & -x;
        x += r;

        if (x != (x & -x)) {
            cout << "No";
            return;
        }
        s = x;

        r = __lg(r);
        s = __lg(s);

        if (a[i] < avg) {
            swap(r, s);
        }
        cnt[r]++;
        cnt[s]--;
    }

    for (int c: cnt) {
        if (c) {
            cout << "No";
            return;
        }
    }

    cout << "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}