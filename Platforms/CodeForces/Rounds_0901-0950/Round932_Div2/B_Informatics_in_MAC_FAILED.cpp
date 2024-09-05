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

    multiset<int> l;
    multiset<int> r(a.begin(), a.end());

    int mL = 0, mR;
    if (r.count(0)) {
        mR = *lower_bound(r.begin(), r.end(), 0) + 1;
    } else {
        mR = 0;
    }

    for (int i = 0; i < n - 1; ++i) {
        // Add a[i] to l and remove it from r
        int x = a[i];
        r.erase(r.find(x));
        if (not r.count(x)) {
            mR = x;
        }
        l.insert(x);
        if (not l.count(x) and mL == x) {
            mL = *lower_bound(l.begin(), l.end(), x) + 1;
        }
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
