#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }

    vector<int> minInd(m, -1), maxInd(m, -1);
    for (int i = 0, j = 0; i < n and j < m; ++i) {
        if (a[i] == b[j]) {
            minInd[j++] = i;
        }
    }
    for (int i = n - 1, j = m - 1; i >= 0 and j >= 0; --i) {
        if (a[i] == b[j]) {
            maxInd[j--] = i;
        }
    }

    /**
     * 
     */

    return 0;
}
