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

    /**
     * Number of subarrays that end at a_i
     * If there is a j > i such that a_j = a_i, we can't end at i
     * If there is a j < i such that a_j = a_i, we can't start at i
     */
    map<int, int> mn, mx;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        if (mn.find(mn[x]) == mn.end()) {
            mn[x] = i;
        }
        mx[x] = i;
    }

    set<int> s;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        s.insert(x);
        if (mx[x] == i) {
            ans += s.size();
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
