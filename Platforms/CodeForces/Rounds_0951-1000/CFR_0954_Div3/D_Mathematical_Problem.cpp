#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> a;
    a.reserve(n);
    for (char &c: s) {
        a.push_back(c - '0');
    }

    vector<ll> dp1(n + 1);
    for (int i = 0; i < n; ++i) {
        dp1[i+1] = dp1[i] + a[i];
        ll cur = a[i];
        for (int j = i-1; j >= 0; --j) {
            cur *= a[j];
            dp1[i+1] = max(dp1[i+1], dp1[j] + cur);
        }
    }

    vector<ll> dp(n + 1);
    for (int i = 1; i < n; ++i) {
        dp[i+1] = dp1[i-1] + 10 * a[i-1] + a[i];
        ll cur = a[i];
        for (int j = i-1; j >= 2; --j) {
            cur *= a[j];
            dp[i+1] = max(dp[i+1]
        }
    }

    cout << dp[n-1];
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
