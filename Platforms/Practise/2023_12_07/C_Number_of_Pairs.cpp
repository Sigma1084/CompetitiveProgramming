#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    // Number of pairs (i, j) such that l <= a[i] + a[j] <= r
    ll ans = 0;
    for (int i = 0, jl = n, jr = n; i < n; ++i) {
        // Least jl such that a[i] + a[jl] >= l
        jl = max(jl, i + 1);
        while (jl - 1 > i and a[i] + a[jl - 1] >= l) {
            --jl;
        }

        // Least jr such that a[i] + a[jr] > r
        jr = max(jr, jl);
        while (jr - 1 > i and a[i] + a[jr - 1] > r) {
            --jr;
        }

        ans += max(0, jr - jl);
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
