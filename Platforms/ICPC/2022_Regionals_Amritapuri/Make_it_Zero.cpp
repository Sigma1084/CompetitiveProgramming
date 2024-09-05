#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline int getMn(const set<int> &s) {
    return __lg(s.size()) + 1;
}
inline int getMx(const set<int> &s) {
    return __lg(*s.rbegin()) + 1;
}

array<map<set<int>, bool>, 7> dp;
bool dpp(const set<int> &a, int k) {
    // Is it possible in k?
    if (int(a.size()) <= 2) {
        return int(a.size()) <= k;
    }

    if (getMn(a) > k) {
        return false;
    } else if (getMx(a) <= k) {
        return true;
    }

    if (dp[k].find(a) != dp[k].end()) {
        return dp[k].at(a);
    }

    set<int> rem;
    set<int> cur = a;
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        cur.erase(*it);
        set<int> b = cur;
        for (auto x: rem) {
            b.insert(x - *it);
        }
        rem.insert(*it);
        if (dpp(b, k - 1)) {
            return dp[k][a] = true;
        }
    }
    return dp[k][a] = false;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    set<int> s{a.begin(), a.end()};

    for (int i = 1; i <= 6; ++i) {
        if (dpp(s, i)) {
            cout << i;
            return;
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
