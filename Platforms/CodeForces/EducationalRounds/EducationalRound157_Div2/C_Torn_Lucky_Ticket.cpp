#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> xs(n), ys(n);
    vector<string> ss(n);
    vector<map<int, int>> mEq(5 + 1);
    map<int, int> m13, m15, m24, m35;

    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        string s = to_string(x);
        int y = 0;
        for (char c: s) {
            y += c - '0';
        }

        // Store
        xs[i] = x;
        ys[i] = y;
        ss[i] = s;

        vector<int> v(s.size());
        for (int j = 0; j < s.size(); ++j) {
            v[j] = s[j] - '0';
        }

        mEq[s.size()][y]++;

        if (s.size() == 3) {
            x = v[2] + v[1] - v[0];
            m13[x]++;
        } else if (s.size() == 4) {
            x = v[3] + v[2] + v[1] - v[0];
            m24[x]++;
        } else if (s.size() == 5) {
            x = v[4] + v[3] + v[2] - v[1] - v[0];
            m15[x]++;
            x = v[4] + v[3] + v[2] + v[1] - v[0];
            m35[x]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        const auto &s = ss[i];
        auto x = xs[i], y = ys[i];

        vector<int> v(s.size());
        for (int j = 0; j < s.size(); ++j) {
            v[j] = s[j] - '0';
        }

        // Add the eq
        ans += mEq[s.size()][y];

        if (s.size() == 1) {
            ans += m13[y];
            ans += m15[y];
        } else if (s.size() == 2) {
            ans += m24[y];
        } else if (s.size() == 3) {
            ans += m35[y];
            ans += mEq[1][v[0] + v[1] - v[2]];
        } else if (s.size() == 4) {
            ans += mEq[2][v[0] + v[1] + v[2] - v[3]];
        } else if (s.size() == 5) {
            ans += mEq[3][v[0] + v[1] + v[2] + v[3] - v[4]];
            ans += mEq[1][v[0] + v[1] + v[2] - v[3] - v[4]];
        }
    }

    cout << ans;

    return 0;
}
