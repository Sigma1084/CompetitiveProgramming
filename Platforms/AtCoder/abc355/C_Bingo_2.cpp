#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> a(m);
    for (auto &[r, c]: a) {
        cin >> r;
        --r;
        c = r % n;
        r = r / n;
    }

    vector<int> rs(n, n), cs(n, n);
    int d1 = n, d2 = n;
    bool rOk = false, cOk = false, dOk = false;

    int ans = -1;

    for (int i = 0; i < m; ++i) {
        auto [r, c] = a[i];

        --rs[r];
        if (rs[r] == 0) {
            rOk = true;
        }
        --cs[c];
        if (cs[c] == 0) {
            cOk = true;
        }
        if (r == c) {
            --d1;
            if (d1 == 0) {
                dOk = true;
            }
        }
        if (r + c == n - 1) {
            --d2;
            if (d2 == 0) {
                dOk = true;
            }
        }
        if (rOk or cOk or dOk) {
            ans = i + 1;
            break;
        }
    }

    cout << ans;

    return 0;
}
