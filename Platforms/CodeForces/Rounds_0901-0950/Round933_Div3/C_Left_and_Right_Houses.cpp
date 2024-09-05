#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int nZL = 0, nOL = 0, nZR, nOR;
    nZR = count(s.begin(), s.end(), '0');
    nOR = n - nZR;

    s.push_back('1');

    int ans = -2;
    for (int i = 0; i <= n; ++i) {
        int nL = i, nR = n - i;
        if (nZL >= (nL + 1) / 2 and nOR >= (nR + 1) / 2) {
            if (abs(2*i - n) < abs(2*ans - n)) {
                ans = i;
            }
        }
        if (s[i] == '0') {
            ++nZL;
            --nZR;
        } else {
            ++nOL;
            --nOR;
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
