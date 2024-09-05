#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (char c: s) {
        if ('a' <= c and c <= 'z') {
            
        } else if ('0' <= c and c <= '9') {
            
        } else {
            cout << "NO";
            return;
        }
    }

    if (is_sorted(s.begin(), s.end())) {
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
