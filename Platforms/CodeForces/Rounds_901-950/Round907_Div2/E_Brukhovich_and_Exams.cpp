#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), g(n-1);
    for (int &x: a) {
        cin >> x;
    }

    int sad = 0;
    for (int i = 0; i + 1 < n; ++i) {
        g[i] = gcd(a[i], a[i+1]);
        if (g[i] == 1) {
            ++sad;
        }
    }

    // Remove all the profitable mids
    for (int i = 1; i + 1 < n and k; ++i) {
        if (a[i-1] != 1 and a[i+1] != 1
                and g[i-1] == 1 and g[i] == 1) {
            a[i] = 0;
            g[i-1] = a[i-1];
            g[i] = a[i+1];
            --k;
            sad -= 2;
        }
    }

    // Remove sequences of 1s
    vector<array<int, 4>> bads;  // [l, r, cost, profit]
    for (int i = 0; i < n; ) {
        if (a[i] != 1) {
            ++i;
            continue;
        }
        bads.push_back({0, 0, 0, 0});
        auto &[l, r, cost, profit] = bads.back();
        l = r = i;
        while (r + 1 < n and a[r + 1] == 1) {
            ++r;
        }
        cost = r - l + 1;
        profit = cost + 1;
        profit -= int(l == 0) + int(r == n - 1);
        i = r + 1;
    }

    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] == 1 or a[i+1] == 1) continue;
        if (g[i] == 1) {
            bads.push_back({i, i+1, 1, 1});
        }
    }

    sort(bads.begin(), bads.end(), [](auto &a, auto &b) {
        auto [l1, r1, c1, p1] = a;
        auto [l2, r2, c2, p2] = b;
        // Maximize profit / cost
        return 1LL * p1 * c2 > 1LL * p2 * c1;
    });

    // Now we need to take 1s one by one
    for (auto [l, r, c, p]: bads) {
        if (k >= c) {
            k -= c;
            sad -= p;
        } else {
            sad -= k - int(c > p);
            break;
        }
    }

    cout << sad;
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
