#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0, j = 0; i < n and j < m; ) {
        if (a[i] > b[j] + k) {
            j++;
        } else if (a[i] < b[j] - k) {
            i++;
        } else {
            ans++, i++, j++;
        }
    }

    cout << ans;

    return 0;
}
