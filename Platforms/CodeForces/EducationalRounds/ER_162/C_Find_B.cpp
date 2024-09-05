#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, nQ;
    cin >> n >> nQ;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<int> ones(n);
    vector<ll> pr(n);
    pr[0] = a[0];
    ones[0] = a[0] == 1;
    for (int i = 1; i < n; ++i) {
        pr[i] = pr[i - 1] + a[i];
        ones[i] = ones[i - 1] + (a[i] == 1);
    }

    while (nQ--) {
        int l, r;
        cin >> l >> r;
        --l, --r;

        ll sm = pr[r] - (l > 0 ? pr[l - 1] : 0);
        int o = ones[r] - (l > 0 ? ones[l - 1] : 0);
        cout << (l != r and sm >= r - l + 1 + o ? "YES" : "NO") << '\n';
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
