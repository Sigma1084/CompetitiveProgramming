#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    bool ans = s.front() == '1' or s.back() == '1';
    for (int i = 0; i + 1 < n; ++i) {
        ans |= s[i] == '1' and s[i+1] == '1';
    }

    cout << (ans ? "YES" : "NO");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
