#include <bits/stdc++.h>
using namespace std;
using ll = long long;

std::vector<int> zF(const std::string &s) {
    int n = static_cast<int>(s.size());
    std::vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        
    }
}

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    if (n % 2) {
        cout << 0;
        return;
    }

    auto work = [&]() -> vector<bool> {
        vector<bool> f(n / 2 + 1);
        f[0] = true;
        auto z = zF(s);
        for (int i = 1; i <= n / 2; ++i) {
            if (z[i] >= i) {
                f[i] = true;
            }
        }
        return f;
    };

    auto f = work();
    reverse(s.begin(), s.end());
    auto b = work();

    int ans = 0;
    for (int i = 0; i <= n/2; ++i) {
        ans += f[i] and b[n/2 - i];
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
