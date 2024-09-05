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

    vector<int> p(n + 1);
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i] + a[i];
    }

    int nQ;
    cin >> nQ;

    while (nQ--) {
        int l, u;
        cin >> l >> u;
        --l;

        // Find r such that p[r+1] - p[l] <= u
        int a = l, r = n - 1;
        while (a <= r) {
            int m = (a + r) / 2;
            if (p[m+1] - p[l] <= u) {
                a = m + 1;
            } else {
                r = m - 1;
            }
        }

        if (r < l) ++r;

        // r is what we want
        if (r < n - 1 and u - (p[r+1] - p[l]) >= (p[r+2] - p[l]) - u) {
            ++r;
        }

        cout << r + 1 << ' ';
    }
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
