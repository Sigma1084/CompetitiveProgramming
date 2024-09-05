#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    for (char c = 'a'; c <= 'h'; ++c) {
        if (c != s[0]) {
            cout << c << s[1] << '\n';
        }
    }

    for (char c = '1'; c <= '8'; ++c) {
        if (c != s[1]) {
            cout << s[0] << c << '\n';
        }
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
