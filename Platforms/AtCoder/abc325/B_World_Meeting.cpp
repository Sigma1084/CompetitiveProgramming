#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 9 to 17
    int n;
    cin >> n;

    array<int, 24> a;
    a.fill(0);
    for (int i = 0; i < n; ++i) {
        int w, x;
        cin >> w >> x;
        a[x] += w;
    }

    int ans = 0;
    for (int i = 0; i < 24; ++i) {
        int cur = 0;
        for (int j = 9; j < 18; ++j) {
            cur += a[(i + j) % 24];
        }
        ans = max(ans, cur);
    }

    cout << ans;

    return 0;
}
