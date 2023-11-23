#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x: a) {
            cin >> x;
        }

        /// [1, 1], [2, 2], [3, 4], [5, 8], ...
        /// [0, 1), [1, 2), [2, 4), [4, 8), ...
        bool ok = true;
        int l = 1, r = 2;
        for (int l = 1, r = 2; l <= n; ) {
            ok &= is_sorted(a.begin() + l, a.begin() + min(n, r));
            l *= 2;
            r *= 2;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
