#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    array<string, 2> s;
    cin >> s[0] >> s[1];

    if (n % 2 == 1) {
        cout << "NO";
        return;
    }

    vector dp(2, vector(n, false));
    queue<array<int, 2>> q;
    q.push({1, n-1});
    while (not q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if (dp[i][j]) {
            continue;
        }
        dp[i][j] = true;
        if (j > 0 and s[i][j-1] == '>') {
            q.push({1^i, j-1});
            if (j - 2 >= 0) {
                q.push({i, j-2});
            }
        }
        if (j + 1 < n and s[i][j+1] == '<') {
            q.push({1^i, j+1});
            if (j + 2 < n) {
                q.push({i, j+2});
            }
        }
    }

    cout << (dp[0][0] ? "YES" : "NO");
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
