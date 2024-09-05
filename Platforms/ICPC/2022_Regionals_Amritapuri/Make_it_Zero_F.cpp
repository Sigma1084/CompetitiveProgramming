#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ostream &operator<<(ostream &os, const set<int> &s) {
    os << "{";
    for (auto x: s) {
        os << x << ", ";
    }
    os << "}";
    return os;
}

int getMn(const set<int> &s) {
    return __lg(s.size()) + 1;
}
int getMx(const set<int> &s) {
    return __lg(*s.rbegin()) + 1;
}

map<set<int>, int> dp;
int dpp(const set<int> &a) {
    if (int(a.size()) <= 2) {
        return int(a.size());
    }
    if (dp.find(a) != dp.end()) {
        return dp.at(a);
    }
    int mn = getMn(a);
    int mx = getMx(a);
    if (mn == mx) {
        return dp[a] = mn;
    }
    int res = mx;
    set<int> rem;
    set<int> cur = a;
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        cur.erase(*it);
        set<int> b = cur;
        for (auto x: rem) {
            b.insert(x - *it);
        }
        rem.insert(*it);
        if (res < getMn(b) + 1) {
            continue;
        }
        res = min(res, 1 + dpp(b));
    }
    return dp[a] = res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    set<int> s{a.begin(), a.end()};

    int ans = dpp(s);
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
