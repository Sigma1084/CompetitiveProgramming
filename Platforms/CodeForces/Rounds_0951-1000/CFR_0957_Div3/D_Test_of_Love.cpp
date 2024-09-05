#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    int cur = 0, w = 0;
    while (cur <= n and w <= k) {
        if (cur == 0 or s[cur - 1] == 'L') {
            // Check if there's another log in the next m steps
            if (cur + m > n) {
                cur += m;
                break;
            }
            bool ok = false;
            for (int i = m; i >= 1 and not ok; --i) {
                if (s[cur + i - 1] == 'L') {
                    ok = true;
                    cur += i;
                }
            }
            if (not ok) {
                cur += m;
            }
        } else if (s[cur - 1] == 'W') {
            w += 1;
            cur += 1;
        } else if (s[cur - 1] == 'C') {
            break;
        }
    }

    if (cur > n and w <= k) {
        cout << "YES";
    } else {
        cout << "NO";
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
