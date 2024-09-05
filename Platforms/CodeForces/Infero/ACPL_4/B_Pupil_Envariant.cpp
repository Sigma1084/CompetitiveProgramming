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

    int l = 0, r = 0, u = 0, d = 0;
    int ans = 0;
    for (char c: s) {
        if (c == 'L') {
            if (r) {
                --r;
                ans += 2;
            } else {
                ++l;
            }
        } else if (c == 'R') {
            if (l) {
                --l;
                ans += 2;
            } else {
                ++r;
            }
        } else if (c == 'U') {
            if (d) {
                --d;
                ans += 2;
            } else {
                ++u;
            }
        } else {
            if (u) {
                --u;
                ans += 2;
            } else {
                ++d;
            }
        }
    }

    cout << ans;

    return 0;
}
