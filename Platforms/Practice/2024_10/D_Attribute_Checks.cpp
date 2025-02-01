#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<int> z;
    z.reserve(m + 1);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            z.push_back(i);
        }
    }
    z.push_back(n);

    vector<vector<int>> dp(m + 1);
    for (int i = 0; i <= m; ++i) {
        dp[i].resize(i);
    }

    for (int i = 0, j = 0; i < n; ++i) {
        if (i == z[j]) {
            ++j;
            continue;
        }

    }

    return 0;
}
