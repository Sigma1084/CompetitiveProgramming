#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (auto &s: a) {
        cin >> s;
    }

    int ans = 0;
    for (char c: "abcde") {
        // Sort based on profits
        auto val = [&](const string &s) -> int {
            int cnt = count(s.begin(), s.end(), c);
            return 2*cnt - s.size();
        };
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            b[i] = val(a[i]);
        }
        sort(b.begin(), b.end(), greater<>());
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += b[i];
            if (cur <= 0) break;
            ans = max(ans, i+1);
        }
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
