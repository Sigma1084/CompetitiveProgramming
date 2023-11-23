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

    sort(a.begin(), a.end());

    // Suppose the first one takes care of (0, i) and the second takes care of (j, n-1)
    // The middle will take care of (i+1, j-1)

    if (n <= 3) {
        cout << 0;
        return;
    }

    auto calc = [&] (int i, int j) {
        tuple<int, int, int> res = {0, 0, 0};
        auto &[x, y, z] = res;
        if (i >= 0) {
            x = (a[i] - a[0] + 1) / 2;
        }
        if (i + 1 <= j - 1) {
            y = (a[j-1] - a[i+1] + 1) / 2;
        }
        if (j < n) {
            z = (a[n-1] - a[j] + 1) / 2;
        }
        return res;
    };

    int ans = INT_MAX;
    for (int i = 0; i < n - 1; ++i) {
        // Suppose the first one takes on a[i]
        int l = i + 1, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            auto [x, y, z] = calc(i, m);
            if (y < z) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        auto [x, y, z] = calc(i, l);
        ans = min(ans, max({x, y, z}));
        tie(x, y, z) = calc(i, r);
        ans = min(ans, max({x, y, z}));
    }

    cout << ans;
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
