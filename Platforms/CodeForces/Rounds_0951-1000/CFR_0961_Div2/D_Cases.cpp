#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, c, k;
    cin >> n >> c >> k;

    string s;
    cin >> s;

    int m = 0, M = (1 << c) - 1;
    vector<int> cnt(c);
    vector<bool> dp(1 << c, true);
    dp[M ^ (1 << (s.back() - 'A'))] = false;
    for (int i = 0; i < k; ++i) {
        if (not cnt[s[i] - 'A']) {
            m ^= 1 << (s[i] - 'A');
        }
        ++cnt[s[i] - 'A'];
    }
    dp[M ^ m] = false;
    for (int i = k; i < n; ++i) {
        if (not cnt[s[i] - 'A']) {
            m ^= 1 << (s[i] - 'A');
        }
        ++cnt[s[i] - 'A'];
        --cnt[s[i - k] - 'A'];
        if (not cnt[s[i - k] - 'A']) {
            m ^= 1 << (s[i - k] - 'A');
        }
        dp[M ^ m] = false;
    }

    int ans = c;
    for (m = M; m >= 0; --m) {
        if (dp[m]) {
            ans = min(ans, __builtin_popcount(m));
            continue;
        }
        for (int i = 0; i < c; ++i) {
            if (m & (1 << i)) {
                dp[m ^ (1 << i)] = false;
            }
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
