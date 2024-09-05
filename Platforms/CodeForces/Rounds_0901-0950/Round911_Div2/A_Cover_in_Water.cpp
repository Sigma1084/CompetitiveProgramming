#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    n++;
    s += '#';

    int cur = 0;
    vector<int> v;
    for (char c: s) {
        if (c == '#') {
            v.push_back(cur);
            cur = 0;
        } else {
            cur++;
        }
    }

    if (ranges::max(v) > 2) {
        cout << 2;
    } else {
        cout << accumulate(v.begin(), v.end(), 0);
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
