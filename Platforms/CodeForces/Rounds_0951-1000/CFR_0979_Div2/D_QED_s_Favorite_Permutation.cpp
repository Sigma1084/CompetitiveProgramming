#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, nQ;
    cin >> n >> nQ;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
        --x;
    }

    string s;
    cin >> s;

    vector<int> r(n);
    iota(r.begin(), r.end(), 0);
    for (int i = 0; i < n; ++i) {
        auto [x, y] = minmax(i, a[i]);
        r[x] = max(r[x], y);
    }

    vector<int> req(n - 1);
    for (int i = 0, j; i < n; i = j) {
        int mr = r[i];
        for (j = i; j <= mr; ++j) {
            mr = max(mr, r[j]);
        }
        for (int k = i; k < mr; ++k) {
            req[k] = 1;
        }
    }

    vector<int> p(n - 1);
    for (int i = 0; i < n; ++i) {
        p[i - (s[i] == 'L')]++;
    }

    int diff = 0;
    for (int i = 0; i < n - 1; ++i) {
        diff += (p[i] < req[i]);
    }

    for (int i; nQ--; ) {
        cin >> i;
        --i;
        if (s[i] == 'L') {
            p[i - 1]--;
            if (p[i - 1] < req[i - 1]) {
                ++diff;
            }
            p[i]++;
            if (p[i] == 1 and req[i]) {
                --diff;
            }
            s[i] = 'R';
        } else {
            p[i]--;
            if (p[i] < req[i]) {
                ++diff;
            }
            p[i - 1]++;
            if (p[i - 1] == 1 and req[i - 1]) {
                --diff;
            }
            s[i] = 'L';
        }
        cout << (diff ? "NO" : "YES") << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
