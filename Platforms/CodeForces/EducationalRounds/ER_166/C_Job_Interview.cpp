#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n + m + 1), t(n + m + 1);
    for (auto &x: p) {
        cin >> x;
    }
    for (auto &x: t) {
        cin >> x;
    }

    int nP = 0;
    for (int i = 0; i < n + m + 1; ++i) {
        nP += p[i] > t[i];
    }

    if (nP <= n) {
        // More testers
        swap(n, m);
        swap(p, t);
    }

    /**
     * Guarentees nP > n
     * The first n programmers are programmers.
     * Only for the first n programmers, the n+1th programmer is a programmer.
     */
    ll ans = 0;
    nP = 0;
    int dif;
    for (int i = 0; i < n + m + 1; ++i) {
        if (nP >= n + 1) {
            ans += t[i];
        } else if (p[i] > t[i]) {
            if (nP == n) {
                dif = p[i] - t[i];
                ans += t[i];
            } else {
                ans += p[i];
            }
            ++nP;
        } else {
            ans += t[i];
        }
    }

    nP = 0;
    for (int i = 0; i < n + m + 1; ++i) {
        if (nP >= n or t[i] > p[i]) {
            cout << ans - t[i] << ' ';
        } else if (p[i] > t[i]) {
            cout << ans - p[i] + dif << ' ';
            ++nP;
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
