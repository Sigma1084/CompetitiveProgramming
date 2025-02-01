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

    constexpr int A = 1e9 + 1;
    auto range = std::ranges::iota_view(0, A);

    auto ans = *ranges::partition_point(range, [&](int k) {
        vector<int> b = a;
        for (int i = n - 1; i >= 2; --i) {
            if (b[i] < k) return false;
            int d = min((b[i] - k) / 3, a[i] / 3);
            b[i] -= 3 * d;
            b[i - 1] += d;
            b[i - 2] += 2 * d;
        }
        return b[0] >= k and b[1] >= k;
    }) - 1;

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
