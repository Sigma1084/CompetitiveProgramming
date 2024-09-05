#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    array<int, 26> f = {};
    for (auto c: s) {
        f[c - 'A']++;
    }

    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        ans += f[i] > i;
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
