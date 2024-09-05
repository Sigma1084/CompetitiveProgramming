#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i-1];
    }

    ll ans = 0;
    for (int i = 1, jl = 1, jr = 1; i <= n; ++i) {
        // First jl such that a[jl] - a[i-1] >= l
        while (jl <= n and a[jl] - a[i-1] < l) {
            ++jl;
        }

        // First jr such that a[jr] - a[i-1] > r
        while (jr <= n and a[jr] - a[i-1] <= r) {
            ++jr;
        }

        cerr << i << ": " << jl << ' ' << jr << '\n';
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
