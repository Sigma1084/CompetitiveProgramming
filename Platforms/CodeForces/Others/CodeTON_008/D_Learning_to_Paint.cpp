#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector a(n, vector(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> dp(n);
    dp[0].push_back(a[0][0]);
    dp[0].push_back(0);
    sort(dp[0].begin(), dp[0].end(), greater<>());

    for (int i = 1; i < n; ++i) {
        // Store [value, j, index]
        priority_queue<array<ll, 3>> pq;
        pq.push({a[0][i], i, 0});
        pq.push({a[1][i], i, 1});
        for (int j = 0; j+2 <= i; ++j) {
            pq.push({dp[j][0] + a[j+2][i], j, 0});
        }
        pq.push({dp[i-1][0], i-1, 0});

        while (not pq.empty() and dp[i].size() < k) {
            auto [value, j, index] = pq.top();
            pq.pop();
            dp[i].push_back(value);
            if (j+2 <= i and index + 1 < dp[j].size()) {
                pq.push({dp[j][index+1] + a[j+2][i], j, index+1});
            } else if (j == i - 1 and index + 1 < dp[j].size()) {
                pq.push({dp[j][index+1], j, index+1});
            }
        }
    }

    for (auto x: dp.back()) {
        cout << x << ' ';
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
