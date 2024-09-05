#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * dp[i] = max(1 + dp[j] | j < i and a[j] ^ i < a[i] ^ j)
 * ans = max(all dp[i])
 */
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        for (int j = max(0, i - 256); j < i; ++j) {
            if ((a[j] ^ i) < (a[i] ^ j)) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }   
        }
    }

    cout << 1 + *max_element(dp.begin(), dp.end());
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
