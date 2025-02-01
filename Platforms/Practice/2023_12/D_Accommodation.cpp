#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int mn = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        int t = std::count(s.begin(), s.end(), '1');

        int d = 0;
        for (int i = 0; i + 1 < m; ++i) {
            if (s[i] == '1' and s[i+1] == '1') {
                ++d;
                ++i;
            }
        }
        mn += t - min(d, m / 4);

        d = 0;
        for (int i = 0; i + 1 < m; ++i) {
            if (s[i] == '0' or s[i+1] == '0') {
                ++d;
                ++i;
            }
        }
        mx += t - max(0, m / 4 - d);
    }

    cout << mn << ' ' << mx << '\n';

    return 0;
}
