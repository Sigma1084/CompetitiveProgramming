#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    string s, t;
    cin >> s >> t;

    string ss, tt;
    for (int i = 0; i < n; ++i) {
        if (i >= k or i + k < n) {
            ss += s[i];
            tt += t[i];
        } else if (s[i] != t[i]) {
            cout << "NO";
            return;
        }
    }

    sort(ss.begin(), ss.end());
    sort(tt.begin(), tt.end());

    cout << (ss == tt ? "YES" : "NO");
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
