#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    int n, k, m;
    cin >> n >> k >> m;

    vector<bool> a(n);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        a[x - 1] = true;
    }

    vector<int> pr(n + 1);
    for (int i = 0; i < n; ++i) {
        pr[i + 1] = pr[i] + a[i];
    }

    int ans = k;
    for (int i = 0; i + k <= n; ++i) {
        ans = min(ans, pr[i + k] - pr[i]);
    }

    cout << ans << '\n';

    return 0;
}
