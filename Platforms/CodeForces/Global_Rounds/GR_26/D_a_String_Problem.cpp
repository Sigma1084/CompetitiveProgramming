#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> getDp(int f, int b) {
    vector<ll> dp(f + b + 1);
    if (f > b) {
        swap(f, b);
    }
    for (int i = 0; i <= f; ++i) {
        dp[i] = i + 1;
    }
    for (int i = f + b, j = 0; i >= b; --i, ++j) {
        dp[i] = j + 1;
    }
    for (int i = f + 1; i < b; ++i) {
        dp[i] = dp[f];
    }
    for (int i = 1; i <= f + b; ++i) {
        dp[i] += dp[i-1];
    }
    return dp;
}

void solve() {
    string s;
    cin >> s;

    vector<int> as;
    string t;

    as.push_back(0);
    for (char c: s) {
        if (c == 'a') {
            as.back() += 1;
        } else {
            t.push_back(c);
            as.push_back(0);
        }
    }

    if (as.size() == 1) {
        cout << s.size() - 1;
        return;
    }

    // Max prefix and max suffix are fixed
    vector<ll> dp = getDp(as.front(), as.back());

    int n = t.size();
    assert(as.size() == n + 1);

    ll ans = 0;
    for (int d = 1; d <= n; ++d) {
        if (n % d) continue;

        bool ok = true;
        for (int i = d; i < n; ++i) {
            if (t[i] != t[i - d]) {
                ok = false;
                break;
            }
            if (i % d and as[i] != as[i-d]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            int m = dp.size() - 1;
            for (int i = d; i < n; i += d) {
                m = min(m, as[i]);
            }
            ans += dp[m];
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
