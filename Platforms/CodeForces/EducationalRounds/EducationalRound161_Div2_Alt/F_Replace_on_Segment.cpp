#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int x, n;
vector<int> a;
vector<vector<int>> pr, nx, prn, nxn;
vector<vector<vector<int>>> dp1, dp2;

int calc1(int l, int r, int k) {
    l = nxn[l][k]; r = prn[r][k];
    if (l > r) return 0;
    if (dp1[l][r][k] != -1) return dp1[l][r][k];
    dp1[l][r][k] = dp2[l][r][k] + 1;  // Make everything not equal and then make equal
    for (int i = l; i < r; ++i) {
        dp1[l][r][k] = min(dp1[l][r][k], calc1(l, i, k) + calc1(i+1, r, k));
    }
    return dp1[l][r][k];
}

int calc2(int l, int r, int k) {
    l = nx[l][k]; r = pr[r][k];
    if (l > r) return 0;
    if (dp2[l][r][k] != -1) return dp2[l][r][k];
    dp2[l][r][k] = dp1[l][r][k] + 1;  // Make everything equal and then make not equal
    for (int i = l; i < r; ++i) {
        dp2[l][r][k] = min(dp2[l][r][k], calc2(l, i, k) + calc2(i+1, r, k));
    }
    return dp2[l][r][k];
}

void solve() {
    cin >> x >> n;

    a.resize(n);
    for (auto &y: a) {
        cin >> y;
        --y;
    }

    /**
     * pr[i][k] = previous index of k in [0, i]
     * prn[i][k] = previous index not equal to k in [0, i]
     */
    pr = vector(n, vector(x, -1));
    prn = vector(n, vector(x, -1));
    pr[0][a[0]] = 0;
    prn[0] = vector(x, 0);
    prn[0][a[0]] = -1;
    for (int i = 1; i < n; ++i) {
        pr[i] = pr[i - 1];
        pr[i][a[i]] = i;
        prn[i] = prn[i - 1];
        for (int k = 0; k < x; ++k) {
            if (k != a[i]) {
                prn[i][k] = i;
            }
        }
    }

    /**
     * nx[i][k] = next index of k in [i, n - 1]
     * nxn[i][k] = next index not equal to k in [i, n - 1]
     */
    nx = vector(n, vector(x, -1));
    nxn = vector(n, vector(x, -1));
    nx[n-1][a[n-1]] = n-1;
    nxn[n-1] = vector(x, n-1);
    nxn[n-1][a[n-1]] = -1;
    for (int i = n-2; i >= 0; --i) {
        nx[i] = nx[i+1];
        nx[i][a[i]] = i;
        nxn[i] = nxn[i+1];
        for (int k = 0; k < x; ++k) {
            if (k != a[i]) {
                nxn[i][k] = i;
            }
        }
    }

    /**
     * dp1[i][j][k] = min cost to make [i, j] equal to k
     * dp2[i][j][k] = min cost to make [i, j] not equal to k
     */
    dp1 = vector(n, vector(n, vector(x, -1)));
    dp2 = vector(n, vector(n, vector(x, -1)));

    int ans = n;
    for (int k = 0; k < x; ++k) {
        ans = min(ans, calc1(0, n-1, k));
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
