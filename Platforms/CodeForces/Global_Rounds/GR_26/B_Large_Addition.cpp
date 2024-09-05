#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;

    string s = to_string(n);

    if (s.front() != '1') {
        cout << "NO";
        return;
    }

    for (int i = 1; i < s.size() - 1; ++i) {
        if (s[i] == '0') {
            cout << "NO";
            return;
        }
    }

    if (n % 10 != 9) {
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
