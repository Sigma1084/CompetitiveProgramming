#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<array<int, 2>> ch(n);
    for (auto &[c1, c2]: ch) {
        cin >> c1 >> c2;
        c1--; c2--;
    }

    // If a node is not a leaf it has to go left or right
    // If a node is going right, then it CAN go left

    function<int(int)> dfs = [&](int u) -> int {
        // Answer is minimum of go right and go left
        if (ch[u][0] == -1 && ch[u][1] == -1) {
            return 0;
        }
        int ans = INT_MAX;
        if (ch[u][0] != -1) {
            ans = min(ans, dfs(ch[u][0]) + (s[u] != 'L'));
        }
        if (ch[u][1] != -1) {
            ans = min(ans, dfs(ch[u][1]) + (s[u] != 'R'));
        }
        return ans;
    };

    cout << dfs(0);
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
