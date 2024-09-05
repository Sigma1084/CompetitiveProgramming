#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    constexpr int N = 'G' - 'A' + 1;
    array<int, N> cnt{};
    for (char c : s) {
        ++cnt[c - 'A'];
    }

    int ans = 0;
    for (auto x: cnt) {
        ans += max(0, m - x);
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
