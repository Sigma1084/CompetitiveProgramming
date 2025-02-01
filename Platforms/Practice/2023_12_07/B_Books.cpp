#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int cur = 0, ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n and cur + a[j] <= t) {
            cur += a[j];
            ++j;
        }
        ans = max(ans, j - i);
        cur -= a[i];
    }

    cout << ans;

    return 0;
}
