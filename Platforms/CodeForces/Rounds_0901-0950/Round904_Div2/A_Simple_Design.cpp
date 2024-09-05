#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x, k;
    cin >> x >> k;

    auto sum = [](string s) {
        int res = 0;
        for (auto c : s) {
            res += c - '0';
        }
        return res;
    };

    while (sum(to_string(x)) % k) {
        x += 1;
    }

    cout << x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
