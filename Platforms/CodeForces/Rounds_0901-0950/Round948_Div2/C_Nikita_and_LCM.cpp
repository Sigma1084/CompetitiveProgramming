#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e18;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    set<int> s(a.begin(), a.end());

    set<int> facts;
    for (auto x: a) {
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                facts.insert(i);
                facts.insert(x / i);
            }
        }
    }

    // After every element, maintain a set of lcms
    // that are possible for considering everything before that element
    int ans = 0;
    map<int, int> dp;
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        map<int, int> newDp;
        for (auto [l, sz]: dp) {
            ll nLcm = l == 0 ? a[i] : lcm(l, a[i]);
            if (facts.find(nLcm) == facts.end()) {
                // We can add anything after this element
                ans = max(ans, sz + n - i);
            } else {
                newDp[nLcm] = max(newDp[nLcm], sz + 1);
            }
        }
        for (auto [l, sz]: newDp) {
            dp[l] = max(dp[l], sz);
        }
    }

    for (auto [l, sz]: dp) {
        if (s.find(l) == s.end()) {
            ans = max(ans, sz);
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