#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, maxK;
    cin >> n >> maxK;

    string s;
    cin >> s;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = (i ? p[i - 1] : 0) + (s[i] == '1');
    }

    /**
     * pref[i+1][k] := Max number of 1s in the prefix of length i
     *                 such that it ends at i
     * 
     * Then change pref[i+1][k] to
     * pref[i+1][k] := Max number of 1s in the prefix of length i
     */
    vector<vector<int>> pref(n + 1, vector<int>(maxK + 1, 0));
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            pref[i + 1][0] = pref[i][0] + 1;
        }
        for (int k = 1; k <= maxK; ++k) {
            if (s[i] == '0') {
                pref[i + 1][k] = pref[i][k - 1] + 1;
            } else {
                pref[i + 1][k] = pref[i][k] + 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k <= maxK; ++k) {
            pref[i + 1][k] = max(pref[i + 1][k], pref[i][k]);
        }
    }

    /**
     * suff[i][k] := Max number of 1s in the suffix [i:]
     *               such that it starts at i
     * 
     * Then change suff[i][k] to
     * suff[i][k] := Max number of 1s in the suffix [i:]
     */
    vector<vector<int>> suff(n + 1, vector<int>(maxK + 1, 0));
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '1') {
            suff[i][0] = suff[i + 1][0] + 1;
        }
        for (int k = 1; k <= maxK; ++k) {
            if (s[i] == '0') {
                suff[i][k] = suff[i + 1][k - 1] + 1;
            } else {
                suff[i][k] = suff[i + 1][k] + 1;
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int k = 0; k <= maxK; ++k) {
            suff[i][k] = max(suff[i][k], suff[i + 1][k]);
        }
    }

    /**
     * For a given l0, find the maximum l1 attainable
     */
    vector<int> maxL1(n + 1, -1);
    assert(pref[n][maxK] == suff[0][maxK]);
    maxL1[0] = pref[n][maxK];

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int l0 = j - i + 1;
            int ch = p[j] - (i ? p[i - 1] : 0);
            if (ch > maxK) {
                // We can not change this substring
                continue;
            }
            int l1 = max(pref[i][maxK - ch], suff[j + 1][maxK - ch]);
            maxL1[l0] = max(maxL1[l0], l1);
        }
    }

    for (int a = 1; a <= n; ++a) {
        int ans = 0;
        for (int l0 = 0; l0 <= n; ++l0) {
            if (maxL1[l0] == -1) {
                continue;
            }
            ans = max(ans, a * l0 + maxL1[l0]);
        }
        cout << ans << ' ';
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
