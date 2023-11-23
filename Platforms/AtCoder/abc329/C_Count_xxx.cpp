#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;
    s += '_';

    int cur = 0;
    char pr = '_';
    map<char, int> mp;
    for (char c: s) {
        if (c == pr) {
            cur += 1;
        } else {
            mp[pr] = max(mp[pr], cur);
            cur = 1;
        }
        pr = c;
    }

    int ans = 0;
    for (auto [c, f]: mp) {
        ans += f;
    }

    cout << ans;

    return 0;
}
