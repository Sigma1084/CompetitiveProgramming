#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int s;
    cin >> s;

    string ss;
    cin >> ss;

    for (char c: ss) {
        s -= c - '0';
    }

    if (1 <= s and s <= 6) {
        cout << "YES";
    } else {
        cout << "NO";
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
