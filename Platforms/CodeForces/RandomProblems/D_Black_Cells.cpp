#include <bits/stdc++.h>
using namespace std;

/**
 * Suppose we take a range [l, r], how much are we spending?
 * r to reach r and 2 extra for shift and unshift
 * So, r + 2
 */
void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> ranges(n);
    for (auto &[l, r]: ranges) cin >> l;
    for (auto &[l, r]: ranges) cin >> r;

    constexpr int INF = 2e9;
    int ans = INF;
    int cur = 0;  // Number of blocks we have taken
    priority_queue<int, vector<int>, greater<>> pq;  // Insert ranges
    for (auto [l, r]: ranges) {
        // We will use the current range
        pq.push(r - l + 1);
        cur += r - l + 1;
        while (!pq.empty() and cur >= k) {
            int req = l - 1 + k - (cur - (r - l + 1));
            ans = min(ans, req + 2 * (int) pq.size());
            cur -= pq.top();
            pq.pop();
        }
    }

    cout << (ans == INF ? -1 : ans);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output_sol.txt", "w", stdout);
    // freopen("log.txt", "a", stderr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
