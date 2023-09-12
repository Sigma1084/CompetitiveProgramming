#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin >> n;
    constexpr int C = 37;

    vector<vector<int>> a(C, vector<int>(n, C + 1));
    for (int i = 0, c; i < n; ++i) {
        cin >> c;
        for (int j = 0; j < c; ++j) {
            cin >> x;
            a[x][i] = c;
        }
    }

    cin >> x;
    int m = *min_element(a[x].begin(), a[x].end());

    if (m == C + 1) m++;

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (a[x][i] == m) {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << '\n';
    for (int x: ans) {
        cout << x << ' ';
    }

    return 0;
}
