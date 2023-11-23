#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    array<int, 2> cnt;
    cnt.fill(0);

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt[x - 1]++;
    }

    int ans = min(cnt[0], cnt[1]);
    cnt[0] -= ans;
    ans += cnt[0] / 3;

    cout << ans;

    return 0;
}
