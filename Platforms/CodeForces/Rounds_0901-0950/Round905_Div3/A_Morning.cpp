#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    int prev = 1, ans = 0, cur;
    for (char c: s) {
        if (c == '0') {
            cur = 10;
        } else {
            cur = c - '0';
        }
        ans += abs(cur - prev);
        prev = cur;
    }

    cout << ans + 4;
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
