#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    set<char> st(s.begin(), s.end());
    map<char, char> mp;
    for (auto f = st.begin(), b = prev(st.end()); f != st.end(); ++f, --b) {
        mp[*f] = *b;
    }

    for (auto c: s) {
        cout << mp[c];
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
