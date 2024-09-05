#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1500;
constexpr array<int, N> preComp() {
    array<int, N> tr{};
    for (int n = 0; n < N; ++n) {
        tr[n] = n * (n - 1) / 2;
    }
    return tr;
}
constexpr array<int, N> tr = preComp();

bool isSq(ll n) {
    int r = sqrt(n);
    return 1LL * r * r == n;
}

void solve() {
    int k;
    cin >> k;

    int x = 1, c = 0;
    vector<array<int, 2>> pts;
    while (k > 0) {
        int n = upper_bound(tr.begin(), tr.end(), k) - tr.begin() - 1;
        k -= tr[n];
        for (int i = 0; i < n; ++i, ++x) {
            pts.push_back({x, x + c});
        }
        ++c;
    }

    // Insert (x, 7x)
    x = 10001;
    int n = int(pts.size());
    while (pts.size() < 2023) {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            auto [x1, y1] = pts[i];
            ll ar = 1LL * abs(x - x1) * abs(7*x - y1);
            if (isSq(ar)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            pts.push_back({x, 7*x});
        }
        ++x;
    }

    for (auto [x, y]: pts) {
        cout << x << ' ' << y << '\n';
    }
    cout << -1;
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
