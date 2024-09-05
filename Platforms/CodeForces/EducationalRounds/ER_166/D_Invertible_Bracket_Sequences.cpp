#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    vector<int> o(s.size() / 2 + 1);
    o[0] = 1;  // 1 valid opening

    int sc = 0;
    ll ans = 0;
    for (auto c: s) {
        if (c == '(') {
            o[sc++ / 2] = 0;
        } else {
            --sc;
        }
        ans += o[sc]++;
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
