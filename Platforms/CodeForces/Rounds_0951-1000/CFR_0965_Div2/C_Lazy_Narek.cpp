#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> b(n);
    for (auto &x: b) {
        cin >> x;
    }

    const string s = "narek";
    vector<vector<int>> a(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = s.find(b[i][j]);
        }
    }

    // Suppose I start from state i
    // I will go to state j with some score

    // sc[i][state] = { score, next_state }
    vector<array<array<int, 2>, 5>> sc(n);
    for (int i = 0; i < n; ++i) {
        for (int sI = 0; sI < 5; ++sI) {
            auto &[score, state] = sc[i][sI];
            score = 0;
            state = sI;
            for (int x: a[i]) {
                if (x == string::npos) {
                    continue;
                } else if (x == state) {
                    score += 1;
                    state = (state + 1) % 5;
                } else {
                    score -= 1;
                }
            }
        }
    }

    constexpr int INF = 1e9;

    // dp[i + 1][state] := Max score when we use first i and end at state state
    vector<array<int, 5>> dp(n + 1);
    dp[0].fill(-INF);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i];
        for (int sI = 0; sI < 5; ++sI) {
            // Go from dp[i][sI] to wherever sc[i][sI] tells us to go
            auto [score, nextState] = sc[i][sI];
            dp[i + 1][nextState] = max(dp[i + 1][nextState], dp[i][sI] + score);
        }
    }

    int ans = 0;
    for (int i = 0; i < 5; ++i) {
        ans = max(ans, dp[n][i] - 2 * i);
    }

    cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
