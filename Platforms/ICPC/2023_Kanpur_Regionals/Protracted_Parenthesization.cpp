#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<ll> dpL(n), dpR(n);

    ll cur = 0;
    int c = 0;  // Counter
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            // Number of closed before
            cur += c;
        } else {
            ++c;
        }
        dpL[i] = cur;
    }

    cur = 0;
    c = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == ')') {
            // Number of open after
            cur += c;
        } else {
            ++c;
        }
        dpR[i] = cur;
    }

    ll ans = 0;
    c = 0;
    for (int i = 0; i < n; ++i) {
        c += s[i] == '(' ? 1 : -1;
        if (c < 0) {
            ans = max(ans, 1 + (i ? dpL[i-1] : 0) 
                + (i+1 < n ? dpR[i+1] : 0));
        }
    }

    c = 0;
    for (int i = n - 1; i >= 0; --i) {
        c += s[i] == ')' ? 1 : -1;
        if (c < 0) {
            ans = max(ans, 1 + (i ? dpL[i-1] : 0)
                + (i+1 < n ? dpR[i+1] : 0));
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
