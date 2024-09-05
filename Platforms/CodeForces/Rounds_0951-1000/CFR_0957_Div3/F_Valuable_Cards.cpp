#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll x;
    cin >> n >> x;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    set<int> f = {1};
    int ans = 1;
    for (int e: a) {
        if (x % e) {
            continue;
        }
        set<int> nf = f;
        for (int d: f) {
            if (x % (1LL * d * e) == 0) {
                nf.insert(d * e);
            }
        }
        f = move(nf);
        if (*f.rbegin() == x) {
            ++ans;
            f = {1, e};
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
