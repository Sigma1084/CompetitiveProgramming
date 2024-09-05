#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n - 1);
    for (auto &x: a) {
        cin >> x;
    }

    int x = 1LL * n * (n + 1) / 2 
            - accumulate(a.begin(), a.end(), 0LL);
    
    cerr << "x = " << x << "\n";

    // Assume x is first
    ll sc = 0;
    for (int i = 0; i + 1 < n; ++i) {
        // a[i] goes at i + 2
        sc += max(a[i], i + 2);
    }

    ll ans = sc + x;
    cerr << "sc = " << sc << "\n";
    for (int i = 0; i < n; ++i) {
        sc -= max(a[i], i + 2);
        sc += max(a[i], i + 1);
        ans = max(ans, sc + max(x, i + 1));
        cerr << "i = " << i << ", sc = " << sc << "\n";
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
