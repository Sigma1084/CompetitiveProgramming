#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s = "aeiou";
    auto [m, r] = std::div(n, 5);

    for (int i = 0; i < 5; ++i) {
        cout << std::string(m + (i < r), s[i]);
    }
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
