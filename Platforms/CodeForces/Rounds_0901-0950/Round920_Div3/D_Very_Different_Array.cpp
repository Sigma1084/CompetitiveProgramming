#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    multiset<int> s;
    for (int i = 0, x; i < m; ++i) {
        cin >> x;
        s.insert(x);
    }

    ll ans = 0;
    int i = 0, j = n - 1;
    while (i <= j) {
        int x = a[i], y = a[j];
        int l = *s.begin(), r = *s.rbegin();
        if (abs(y - l) > abs(r - x)) {
            ans += abs(y - l);
            s.erase(s.begin());
            --j;
        } else {
            ans += abs(r - x);
            s.erase(--s.end());
            ++i;
        }
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
