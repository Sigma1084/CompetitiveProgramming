#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s = to_string(n);

    vector<array<int, 2>> ans;

    for (int a = 1; a <= 10000; ++a) {
        // We compute maxB
        int numDigs = a * s.size();
        int num = 0;
        for (int d = 0; d < min(5, numDigs); ++d) {
            num = num * 10 + s[d % s.size()] - '0';
            // Number after removing b + 1 digits
            int b = numDigs - d - 1;
            if (num == n * a - b and b > 0) {
                ans.push_back({a, b});
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto [a, b] : ans) {
        cout << a << ' ' << b << '\n';
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
