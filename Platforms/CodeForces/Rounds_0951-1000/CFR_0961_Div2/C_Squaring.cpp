#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    reverse(a.begin(), a.end());
    while (not a.empty() and a.back() == 1) {
        a.pop_back();
    }
    reverse(a.begin(), a.end());

    int c = 0;
    ll p = 2, ans = 0;
    for (int _x: a) {
        ll x = _x;
        if (x == 1) {
            ans = -1;
            break;
        }
        if (p * p <= x) {
            while (p * p <= x) {
                --c;
                p *= p;
            }
        } else {
            while (p > x) {
                ++c;
                x *= x;
            }
        }
        if (c < 0) {
            c = 0;
        }
        p = _x;
        ans += c;
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
