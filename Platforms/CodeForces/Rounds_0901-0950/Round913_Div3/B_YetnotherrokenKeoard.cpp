#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = int(s.size());
    vector<pair<char, int>> lower, upper;
    for (int i = 0; i < n; ++i) {
        if (islower(s[i])) {
            if (s[i] != 'b') {
                lower.push_back({s[i], i});
            } else if (!lower.empty()) {
                lower.pop_back();
            }
        } else {
            if (s[i] != 'B') {
                upper.push_back({s[i], i});
            } else if (!upper.empty()) {
                upper.pop_back();
            }
        }
    }

    auto ans = lower;
    ans.insert(ans.end(), upper.begin(), upper.end());
    sort(ans.begin(), ans.end(), [](auto a, auto b) {
        return a.second < b.second;
    });

    for (auto [c, i] : ans) {
        cout << c;
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
