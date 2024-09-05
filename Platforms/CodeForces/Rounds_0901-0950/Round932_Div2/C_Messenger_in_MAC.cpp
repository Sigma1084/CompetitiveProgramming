#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e16;

void solve() {
    int n, l;
    cin >> n >> l;

    vector<array<int, 2>> arr(n);
    for (auto &[a, b]: arr) {
        cin >> a >> b;
    }
    sort(arr.begin(), arr.end(), [](auto &e1, auto &e2) {
        return e1[1] < e2[1];
    });

    /**
     * dp[i][j] := Consider a subsequence in arr[0...i]
     *    ending at i, what is the min cost
     *    to take exactly j elements other than it
     */
    vector dp(n, vector(n, INF));
    for (int i = 0; i < n; ++i) {
        dp[0][i] = arr[i][0] - arr[i][1];
    }
    // Then, we just add a[i] to it

    for (int j = 1; j < n; ++j) {
        auto mn = *min_element(dp[j-1].begin(), dp[j-1].begin() + j);
        for (int i = j; i < n; ++i) {
            dp[j][i] = arr[i][0] + mn;
            mn = min(mn, dp[j-1][i]);
        }
    }

    for (int j = 0; j < n; ++j) {
        for (int i = j; i < n; ++i) {
            dp[j][i] += arr[i][1];
        }
    }

    // We need to find the least i such
    int ans = 0;
    while (ans < n) {
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (dp[ans][i] <= l) {
                ans++;
                ok = true;
                break;
            }
        }
        if (not ok) {
            break;
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
