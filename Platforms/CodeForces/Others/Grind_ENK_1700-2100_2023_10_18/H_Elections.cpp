#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector a(m, vector(n, 0));
    for (auto &row: a) {
        for (auto &x: row) {
            cin >> x;
        }
    }

    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 0);

    int ans = 0;
    vector<int> ansVec = ord;

    for (int i = 0; i + 1 < n; ++i) {
        // Suppose candidate i is challenging
        sort(ord.begin(), ord.end(), [&](int x, int y) {
            return a[x][i] - a[x][n-1] > a[y][i] - a[y][n-1];
        });

        int diff = 0, j = 0;
        while (j < m) {
            int cur = a[ord[j]][i] - a[ord[j]][n-1];
            if (diff + cur < 0) {
                break;
            } else {
                diff += cur;
                ++j;
            }
        }

        if (j > ans) {
            ans = j;
            ansVec.clear();
            while (j < m) {
                ansVec.push_back(ord[j++]);
            }
        }
    }

    cout << m - ans << '\n';
    for (int x: ansVec) {
        cout << x + 1 << ' ';
    }
    cout << '\n';

    return 0;
}
