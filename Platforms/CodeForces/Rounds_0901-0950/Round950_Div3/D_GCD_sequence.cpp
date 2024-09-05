#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<int> b(n - 1);
    for (int i = 0; i + 1 < n; ++i) {
        b[i] = gcd(a[i], a[i+1]);
    }

    vector<bool> fr(n - 1), bk(n - 1);
    fr.front() = bk.back() = true;
    for (int i = 1; i + 1 < n; ++i) {
        fr[i] = fr[i-1] and (b[i-1] <= b[i]);
    }
    for (int i = n - 3; i >= 0; --i) {
        bk[i] = bk[i+1] and (b[i] <= b[i+1]);
    }

    // Removing the first or the last element
    if (bk[1] or fr[n-3]) {
        cout << "YES";
        return;
    }

    for (int i = 1; i + 1 < n; ++i) {
        /**
         * 0...i-1, i, i+1...n-1
         * i-1, i will change
         */
        if (i >= 2 and !fr[i-2]) continue;
        if (i + 1 < n - 1 and !bk[i+1]) continue;

        vector<int> cur;
        if (i >= 2) {
            cur.push_back(b[i-2]);
        }
        if (i >= 1) {
            cur.push_back(gcd(a[i-1], a[i+1]));
        }
        if (i + 1 < n - 1) {
            cur.push_back(b[i+1]);
        }
        if (is_sorted(cur.begin(), cur.end())) {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
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
