#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    k = n - k;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    int ans = INT_MAX;
    for (int i = 0, j = k - 1; j < n; ++i, ++j) {
        ans = min(ans, a[j] - a[i]);
    }

    cout << ans;

    return 0;
}
