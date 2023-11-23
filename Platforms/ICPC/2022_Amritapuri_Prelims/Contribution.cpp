#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s, t;
    cin >> s >> t;

    int ans = 0;
    for (char c: s) {
        if (c == '1') {
            ans += 1;
        } else if (c == '3') {
            ans += 4;
        } else if (c == '5') {
            ans += 6;
        } else {
            ans += 9;
        }
    }

    for (char c: t) {
        if (c == '1') {
            ans -= 1;
        } else if (c == '3') {
            ans -= 4;
        } else if (c == '5') {
            ans -= 6;
        } else {
            ans -= 9;
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


// 01:56:30