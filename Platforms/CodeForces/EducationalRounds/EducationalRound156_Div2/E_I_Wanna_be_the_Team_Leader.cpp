#include <bits/stdc++.h>
using namespace std;

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // numPpl, numJobs
    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i + 1;
    }

    for (auto &x: b) {
        cin >> x;
    }

    sort(a.begin(), a.end(), greater<>());

    // dp[k][i] := min j such that [i, j) can perform job k
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int k = 0; k < m; ++k) {
        for (int i = 0, j = 0; i < n and j < n; ++i) {
            // a[j][0] is the last person's stress level
            while (j < n and b[k] > 1LL * (j - i + 1) * a[j][0]) {
                j++;
            }
            // We will take [i, dp[k][i]) for job k
            if (j < n) {
                dp[k][i] = j + 1;
            }
        }
    }

    // val[mask] := minimum number of people to perform the jobs in mask
    vector<int> val(1 << m, -1);
    val[0] = 0;
    for (int mask = 1; mask < (1 << m); ++mask) {
        for (int k = 0; k < m; ++k) {
            if (!(mask & (1 << k))) continue;

            // Try performing mask ^ (1 << k) first and then job k

            // Can not perform mask ^ (1 << k)
            if (val[mask ^ (1 << k)] == -1) continue;

            int j = val[mask ^ (1 << k)];

            if (j == n or dp[k][j] == -1) continue;
            if (val[mask] == -1) {
                val[mask] = dp[k][j];
            } else {
                val[mask] = min(val[mask], dp[k][j]);
            }
        }
    }

    if (val[(1 << m) - 1] == -1) {
        cout << "NO";
        return 0;
    }

    int mask = (1 << m) - 1;
    vector<int> ord;
    while (mask) {
        // Find a possible job
        for (int k = 0; k < m; ++k) {
            if (!(mask & (1 << k))) continue;

            // Check if we will reach this state from the previous
            int j = val[mask ^ (1 << k)];
            if (j == -1 or dp[k][j] != val[mask]) continue;

            // Now, we will perform this job (at the end)
            ord.push_back(k);
            mask ^= (1 << k);
            break;
        }
    }

    reverse(ord.begin(), ord.end());

    vector<vector<int>> ans(m);
    for (int i = 0, k = 0; k < m; ++k) {
        int j = dp[ord[k]][i];
        while (i < j) {
            ans[ord[k]].push_back(a[i++][1]);
        }
    }

    cout << "YES\n";
    for (const auto &v: ans) {
        cout << v.size() << " ";
        for (auto x: v) {
            cout << x << " ";
        }
        cout << "\n";
    }
    cout << endl;

    return 0;
}
