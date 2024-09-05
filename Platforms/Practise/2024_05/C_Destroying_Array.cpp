#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<int> ord(n);
    for (auto &x: ord) {
        cin >> x;
        x--;
    }

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }

    auto get = [&](int l, int r) {
        return pref[r+1] - pref[l];
    };

    multiset<ll> ss;
    ss.insert(0);
    set<pair<int, int>> rs;
    rs.insert({0, n-1});
    ss.insert(get(0, n-1));
    for (auto i: ord) {
        auto it = prev(rs.upper_bound({i, n}));
        auto [l, r] = *it;
        rs.erase(it);
        ss.erase(ss.find(get(l, r)));

        if (l <= i-1) {
            rs.insert({l, i-1});
            ss.insert(get(l, i-1));
        }
        if (i+1 <= r) {
            rs.insert({i+1, r});
            ss.insert(get(i+1, r));
        }

        cout << *ss.rbegin() << '\n';
    }

    return 0;
}
