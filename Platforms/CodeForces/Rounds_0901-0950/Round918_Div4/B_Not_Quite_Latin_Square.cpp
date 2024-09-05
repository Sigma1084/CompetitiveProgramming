#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    vector<string> b(3);
    for (auto &s: b) {
        cin >> s;
    }

    for (int i = 0; i < 3; ++i) {
        if (std::find(b[i].begin(), b[i].end(), '?') != b[i].end()) {
            set<char> s = {'A', 'B', 'C'};
            for (auto c: b[i]) {
                s.erase(c);
            }
            cout << *s.begin();
            return;
        }
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
